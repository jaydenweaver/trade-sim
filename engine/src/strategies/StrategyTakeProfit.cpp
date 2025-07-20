#include "StrategyTakeProfit.h"

void StrategyTakeProfit::init() {
    test.strategy_name = strategy_name;
}

void StrategyTakeProfit::on_tick(const Tick& tick) {
    double price = tick.close;

    if (test.buys.empty()) buy(tick, price);
    if (price >= buy_price + (buy_price * target_return)) sell(tick, price);

}

void StrategyTakeProfit::buy(const Tick& tick, double& price) {
    test.start_date = tick.date;
    test.buys.push_back(Buy{
        .date = tick.date,
        .price = price,
        .units = buy_units
    });
    buy_price = price;
    test.units += buy_units;
}

void StrategyTakeProfit::sell(const Tick& tick, double& price) {
    size_t sell_units = static_cast<size_t>(buy_units * sell_portion);
    test.sells.push_back(Sell{
        .date = tick.date,
        .price = price,
        .units = sell_units
    });
    test.units -= sell_units;
}