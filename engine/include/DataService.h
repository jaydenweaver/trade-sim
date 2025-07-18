#pragma once

#include "Tick.h"
#include <vector>
#include <string>

class DataService {
    public:

        DataService(const std::string& api_key);
        std::vector<Tick> get_ticks(const std::string& symbol, const std::string& start, const std::string& end);

    private:

        std::string api_key;
};