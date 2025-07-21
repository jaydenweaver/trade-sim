#pragma once

#include "StrategyBase.h"
#include "Events.h"
#include <string>

class StrategyTakeProfit : public StrategyBase {
    public:
        explicit StrategyTakeProfit(const double& target_return, const double& sell_portion, const double& stop_loss)
        : target_return(target_return), sell_portion(sell_portion), stop_loss(stop_loss) {}; 

        void init();
        void on_tick(const Tick& tick) override;
        //std::string get_result() const override;

        Test test;
        const Test& get_test() const override { return test; }
    private:
        // greater than 0 - e.g. value of 0.3 is 130% of buy value
        double target_return;
        // between 1 and 0 - e.g. value of 0.3 sells 30% of units
        double sell_portion;
        // between 1 and 0 - e.g. value of 0.3 stops at 30% loss
        double stop_loss = 1;
        double buy_price;
        size_t buy_units = 100;
        std::string strategy_name = "Take profit";
        void buy(const Tick& tick, double& price);
        void sell(const Tick& tick, double& price);
        void reset_target(double& price);
};