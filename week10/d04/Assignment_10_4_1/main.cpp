#include <fmt/core.h>
#include <fstream>
#include <cassert>
#include <string>
#include <iostream>
#include <nlohmann/json.hpp>
#include "backward.hpp"

using json = nlohmann::json;

namespace backward {

backward::SignalHandling sh;

} // namespace backward

int main()
{
    std::string arg = "Bloody hell";
    fmt::print("{} Mary {}!\n", arg, "Ann");
    
    std::ifstream f("eurooppa.json");
    json data = json::parse(f);
    std::cout << data << '\n';
    data["benelux-maat"] = {
        {"Alankomaat", "Amsterdam"},
        {"Belgia", "Bryssel"},
        {"Luxemburg", "Luxemburg"}
    };

    std::ofstream o("eurooppa2.json");
    o << std::setw(4) << data << std::endl;

    assert(0);

    return 0;
}
