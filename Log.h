#pragma once
#include <string>
#include <iostream>

namespace Log{
    static void info(const std::string& message){
    std::cout << "[info] " << message << '\n';
}
}
