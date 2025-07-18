#include <iostream>
#include "DataService.h"

int main() {
    std::string csv_path = "../data/tqqq.csv";

    DataService dataService(csv_path);

    std::vector<Tick> ticks = dataService.process_data();

    std::cout << "Parsed " << ticks.size() << " ticks:" << std::endl;

    for (const auto& tick : ticks) {
        std::cout << "Date: " << tick.date
                  << ", Close: " << tick.close
                  << ", Open: " << tick.open
                  << ", High: " << tick.high
                  << ", Low: " << tick.low
                  << ", Volume: " << tick.volume
                  << ", Change: " << tick.change
                  << std::endl;
    }

    return 0;
}