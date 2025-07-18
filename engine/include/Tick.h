#pragma once

#include <string>

struct Tick {
    std::string date;
    double close;
    double open;
    double high;
    double low;
    std::string volume;
    double change;
};