#include <DataService.h>

#include <fstream>
#include <sstream>
#include <iostream>

DataService::DataService(const std::string& file_path) : file_path(file_path) {}

void DataService::set_file(const std::string& file_path) {
    this->file_path = file_path;
}

// strictly requires row format: date, close, open, high, low, volume, change (see line 58)
std::vector<Tick> DataService::process_data() {
    std::vector<Tick> ticks;
    std::string csv_data = read_csv();

    std::istringstream stream(csv_data);
    std::string line;

    // skip header
    std::getline(stream, line);

    while (std::getline(stream, line)) 
        ticks.push_back(process_row(line));

    if (ticks.empty()) {
        std::cerr << "error! no ticks loaded" << std::endl;
        return ticks;
    }

    // reverse vector if csv stores earlier dates towards the top
    if (!is_earlier(ticks.front().date, ticks.back().date)) std::reverse(ticks.begin(), ticks.end());

    return ticks;
}

std::string DataService::read_csv() const {
    std::ifstream file(file_path);

    if (!file.is_open()) {
        std::cerr << "failed to open file: " << file_path << std::endl;
        return "";
    }

    std::ostringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

Tick DataService::process_row(const std::string& line) const {

    std::istringstream ss(line);
    std::string value;
    std::vector<std::string> values;

    while (std::getline(ss, value, ',')){
        // trim quotes if needed
        if (value.size() >= 2 && value.front() == '"' && value.back() == '"')
            value = value.substr(1, value.size() - 2);

        values.push_back(value);
    }

    if (values.size() != FIELD_COUNT) {
        std::cerr << "skipping malformed line" << std::endl;
        return Tick{};
    }

    // trim % off change if needed
    if (values[CHANGE].back() == '%') values[CHANGE] = values[CHANGE].substr(0, values[CHANGE].size() - 1);

    // convert date string to chrono format
    std::chrono::year_month_day date;
    std::istringstream iss(values[DATE]);
    iss >> std::chrono::parse("%m/%d/%Y", date);

    Tick tick;

    try {
        tick = Tick(date, values);
    } catch (const std::exception& e) {
        std::cerr << "error parsing tick: " << e.what() << std::endl;
        return Tick{};
    }

    return tick;
}

bool DataService::is_earlier(const std::chrono::year_month_day& value, const std::chrono::year_month_day& compare) const {
    return std::chrono::sys_days(value) < std::chrono::sys_days(compare);
}
