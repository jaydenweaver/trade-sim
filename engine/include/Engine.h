#pragma once

#include "Tick.h"
#include <vector>
#include <string>

class Engine {
    public:

        Engine() = default;
        ~Engine() = default;

        void load_ticks(const std::vector<Tick>& ticks);
        void run_test();
        std::vector<std::string> get_results() const;
        void reset();

    private:

        std::vector<Tick> data;
        std::vector<std::string> results;

        void process_tick(const Tick& tick);
};