#pragma once

#include "StrategyBase.h"
#include "Events.h"
#include <string>

class StrategyTakeProfit : public StrategyBase {
    public:
        explicit StrategyTakeProfit(const double& target_return, const double& sell_portion)
        : target_return(target_return), sell_portion(sell_portion) {}; 

        void init();
        void on_tick(const Tick& tick) override;
        std::string get_result() const override;

    private:
        Test test;

        double target_return;
        double sell_portion;
        double buy_price;
        size_t buy_units = 100;
        std::string strategy_name = "Take profit";
        void buy(const Tick& tick, double& price);
        void sell(const Tick& tick, double& price);
        void reset_target(double& price);
};