#include "../include/shhtui.hpp"
#include <iterator>
#include <unistd.h>

int main() {
    shhtui::core::startup();

    shhtui::app::C_Application app;
    shhtui::app::C_View mainMenuView("MainMenu");

    shhtui::renderer::clearScreen();

    mainMenuView.addWidget(new shhtui::widgets::Label(
            {1,1},
            std::string("Press 'q' to quit! - Hello from SHHCHA!")));


    mainMenuView.addWidget(new shhtui::widgets::Button(
        {4,4},
        {3,14},
        std::string("Click Me!")));

    app.setActiveView(&mainMenuView);
    // app._activeView->_widgets.at(0)->draw();
    // shhtui::renderer::refreshScreen();
    app.run();
    return shhtui::core::shutdown();
}