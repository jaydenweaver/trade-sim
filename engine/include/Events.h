#pragma once

#include <string>
#include <vector>
#include <chrono>

struct Buy {
    std::chrono::year_month_day date;
    double price;
    std::size_t units;
};

struct Sell {
    std::chrono::year_month_day date;
    double price;
    std::size_t units;
};

struct Test{
    std::string strategy_name;
    std::vector<Buy> buys;
    std::vector<Sell> sells;
    size_t units = 0;
    double average_buy() const;
    bool finished = false;
};