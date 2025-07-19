#pragma once

#include "Tick.h"
#include <vector>
#include <string>
#include <chrono>

// DataService processes CSV files into clean data
// currently only supports CSV files with row format: date, close, open, high, low, volume, change
// any rows that don't have exactly 7 fields will be omitted during parse.
// also note that first line (header) is skipped
class DataService {
    public:
        DataService() = default;
        explicit DataService(const std::string& file_path);

        ~DataService() = default;
        
        void set_file(const std::string& file_path);
        std::vector<Tick> process_data();

    private:
        std::string read_csv() const;
        Tick process_row(const std::string& line) const;
        std::string file_path;
};