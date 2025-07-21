#include <Engine.h>

#include <iostream>

void Engine::load_ticks(const std::vector<Tick>& ticks) { data = ticks; }

void Engine::set_strategy(std::unique_ptr<StrategyBase> s) {
    strategy = std::move(s);
}

void Engine::run_strategy() {
    if (!strategy) {
        std::cerr << "no strategy selected" << std::endl;
        return;
    }

    //strategy -> reset();
    for (const Tick& tick : data) {
        strategy -> on_tick(tick);
    }
}

std::vector<std::string> Engine::get_results() const {

}