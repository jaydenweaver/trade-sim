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
        ticks.insert(ticks.end(), process_row(line));

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
    Tick tick;

    std::istringstream ss(line);
    std::string value;
    std::vector<std::string> values;

    while (std::getline(ss, value, ','))
        values.push_back(value);

    if (values.size() != 7) {
        std::cerr << "skipping malformed line" << std::endl;
        return tick;
    }

    tick.date = values[0];
    tick.close = std::stod(values[1]);
    tick.open = std::stod(values[2]);
    tick.high = std::stod(values[3]);
    tick.low = std::stod(values[4]);
    tick.volume = values[5];
    tick.change = std::stod(values[6]);

    return tick;
}

