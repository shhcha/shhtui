// src/renderer.cpp
#include "../include/renderer.hpp"
#include "../include/util.hpp"


#include <iostream>

namespace shhtui::renderer {

bool start() {
    clearConsole();
    return 1;
}

bool clearConsole() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
    return 1;
}

bool _drawRawText(std::tuple<int, int> position, std::string message) {
    shhtui::util::moveCursor(position);
    std::cout << message;
    return 1;
}


} // namespace shhtui::renderer
