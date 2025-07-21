#include <iostream>
#include "DataService.h"
#include "Engine.h"

// just load and process tqqq.csv for now...
int main() {
    std::string csv_path = "../data/tqqq.csv";

    DataService dataService(csv_path);
    Engine engine{};

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<Tick> ticks = dataService.process_data();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> duration = end - start;

    //engine.load_ticks(ticks); 
    //engine.set_strategy(std::make_unique<StrategyTakeProfit>(0.1, 0.91));
    //engine.run_strategy();

    std::cout << "parsed " << ticks.size() << " ticks in " << duration.count() << " microseconds:" << std::endl;

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