#include <iostream>
#include "Engine.h"

int main() {
    std::cout << GetTestInt() << std::endl;
    
    auto console = spdlog::stdout_color_mt("console");
    console->info("Welcome to spdlog!");
}
