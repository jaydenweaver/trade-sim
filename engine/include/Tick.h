#pragma once

#include <string>
#include <vector>
#include <chrono>

enum TickField {
    DATE,
    CLOSE,
    OPEN,
    HIGH,
    LOW,
    VOLUME,
    CHANGE,
    FIELD_COUNT
};

struct Tick {
    std::chrono::year_month_day date;
    double close;
    double open;
    double high;
    double low;
    std::string volume;
    double change;

    Tick() = default;

    Tick(const std::chrono::year_month_day& date, std::vector<std::string>& values)
        : date(date),
          close(std::stod(values[CLOSE])),
          open(std::stod(values[OPEN])),
          high(std::stod(values[HIGH])),
          low(std::stod(values[LOW])),
          volume(values[VOLUME]),
          change(std::stod(values[CHANGE])) {};
};