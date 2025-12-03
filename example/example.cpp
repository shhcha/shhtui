#include "../include/shhtui.hpp"
#include <charconv>
#include <iostream>
#include <string_view>
#include <unistd.h>
#include <format>

int main() {
    shhtui::util::start();
    shhtui::renderer::start();
    std::cout << std::string("Raw mode enabled. Press 'q' to quit.\n");
    char c;
    while (read(STDIN_FILENO, &c, 1) == 1) {
        if (c == 'q') break;

        // for (int i=2;i<=3;i++)
        //         shhtui::renderer::_drawRawText(std::tuple<int,int>{i,4}, std::format("You pressed {}", c));

        for (int i=0; i<=5; i++)
            for (int j=0;j<=2;j++)
            {
                shhtui::renderer::_drawRawText(std::tuple<int,int>{i,j}, std::string("X"));
            }

        std::cout.flush(); //Print updates to Console
    }

    return 0;
}
