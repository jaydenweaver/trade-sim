#include "StrategyTakeProfit.h"

void StrategyTakeProfit::init() {
    test.strategy_name = strategy_name;
}

void StrategyTakeProfit::on_tick(const Tick& tick) {
    double price = tick.close;

    if (test.buys.empty()) {
        test.start_date = tick.date;
        test.buys.push_back(Buy{
            .date = tick.date,
            .price = price,
            .units = 100
        });
    }
}