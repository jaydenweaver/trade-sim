#pragma once

#include "StrategyBase.h"
#include "Events.h"
#include <string>

class StrategyTakeProfit : public StrategyBase {
    public:
        void on_tick(const Tick& tick) override;
        std::string get_result() const override;

    private:
        Test test;

        // TODO: find a more maintainable place to store these values
        double target_return = 0.1;
        double sell_portion = 0.91;
};