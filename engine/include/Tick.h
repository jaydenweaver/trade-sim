#pragma once

#include <string>
#include <vector>

struct Tick {
    std::string date;
    double close;
    double open;
    double high;
    double low;
    std::string volume;
    double change;

    Tick() = default;

    Tick(const std::vector<std::string>& values)
        : date(values[0]),
          close(std::stod(values[1])),
          open(std::stod(values[2])),
          high(std::stod(values[3])),
          low(std::stod(values[4])),
          volume(values[5]),
          change(std::stod(values[6])) {};
};