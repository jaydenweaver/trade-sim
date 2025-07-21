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

    strategy -> init();
    for (const Tick& tick : data) {
        strategy -> on_tick(tick);
    }

    Test test = strategy->get_test();
    double profit = 0;
    for (const Buy& buy : test.buys) profit -= (buy.price * buy.units);
    for (const Sell& sell : test.sells) profit += (sell.price * sell.units);
    std::cout << "finished strategy with " << strategy->get_test().buys.size() << " buys and " << strategy->get_test().sells.size() << " sells for a profit of: $" << profit << std::endl;
}

//std::vector<std::string> Engine::get_results() const {
//}