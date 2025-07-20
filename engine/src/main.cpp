#include <iostream>
#include "DataService.h"
#include "Engine.h"

// just load and process tqqq.csv for now...
int main() {
    std::string csv_path = "../data/tqqq.csv";

    DataService dataService(csv_path);
    Engine engine{};

    std::vector<Tick> ticks = dataService.process_data();
    engine.load_ticks(ticks); 
    engine.set_strategy(std::make_unique<StrategyTakeProfit>(0.1, 0.91));

    std::cout << "parsed " << ticks.size() << " ticks:" << std::endl;

    for (const auto& tick : ticks) {
        std::cout << "date: " << tick.date
                  << ", close: " << tick.close
                  << ", open: " << tick.open
                  << ", high: " << tick.high
                  << ", low: " << tick.low
                  << ", volume: " << tick.volume
                  << ", change: " << tick.change
                  << std::endl;
    }

    return 0;
}