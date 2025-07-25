#pragma once

#include "Tick.h"
#include "Events.h"
#include <string>

class StrategyBase {
    public:
        virtual ~StrategyBase() = default;

        virtual void init() {}

        virtual void on_tick(const Tick& tick) = 0;

        //virtual std::string get_result() const = 0;

        virtual void reset() {}

        virtual const Test& get_test() const = 0;
};