// util.cpp
#include "../include/util.hpp"

namespace shhtui::util {

// Moves text cursor to {r,c} in terminal
bool _moveCursor(std::tuple<int, int> position) {
    std::cout << "\033[" << std::get<0>(position) << ';' 
                        << std::get<1>(position) << 'H';
    return 1;
}

}
