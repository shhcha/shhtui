#include "../shhtui.hpp"
#include <memory>
#include <unistd.h>


int main()
{
    shhtui::utilities::startupTUI();

    auto myStyle = shhtui::datatypes::S_TextStyle{
        false,
        true,
        true,
        shhtui::datatypes::S_ColorRgb{200,120,180},
        shhtui::datatypes::S_ColorRgb{40,40,40},
        0,
        0
    };

    shhtui::render::pushStyle(myStyle);

    auto myApp = std::make_unique<shhtui::core::C_AppCore>();

    auto myView = std::make_shared<shhtui::core::C_View>("mainView");

    auto testWidget = std::make_shared<shhtui::widgets::C_SimpleLabel>
    (
        shhtui::datatypes::S_Point{5,5},
        shhtui::datatypes::S_Dimension{5,5},
        std::string("ID_01"),
        std::string("Welcome to shhtui!")
    );


    myView->addWidget(testWidget);

    myApp->setView(myView);

    while (myApp->_isRunning)
    {
        myApp->run();
    }
    
    sleep(3);
    return 1;
};