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
    std::chrono::year_month_day start_date;
    std::chrono::year_month_day end_date;
    std::vector<Buy> buys;
    std::vector<Sell> sells;
    double average_buy() const;
};