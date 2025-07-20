#pragma once

#include "Tick.h"
#include "StrategyBase.h"
#include "StrategyTakeProfit.h"
#include <vector>
#include <string>
#include <memory>

class Engine {
    public:
        Engine() = default;
        ~Engine() = default;

        void load_ticks(const std::vector<Tick>& ticks);
        void set_strategy(std::unique_ptr<StrategyBase> s);
        void run_strategy();
        std::vector<std::string> get_results() const;

    private:
        std::vector<Tick> data;
        std::unique_ptr<StrategyBase> strategy;
};