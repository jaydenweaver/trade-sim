#include <iostream>
#include "DataService.h"
#include "Engine.h"

// just load and process tqqq.csv for now...
int main() {
    std::string csv_path = "../data/tqqq.csv";

    DataService data_service(csv_path);
    Engine engine{};

    std::vector<Tick> ticks = data_service.process_data();

    engine.load_ticks(ticks); 
    engine.set_strategy(std::make_unique<StrategyTakeProfit>(0.1, 1.0, 0.1));
    engine.run_strategy();

    return 0;
}