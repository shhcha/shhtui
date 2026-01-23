#include "../shhtui.hpp"
#include <chrono>
#include <memory>
#include <thread>
#include <unistd.h>


int main()
{
    shhtui::utilities::startupTUI();

    auto myStyle = shhtui::datatypes::S_TextStyle{
        false,
        true,
        true,
        shhtui::datatypes::S_ColorRgb{22,255,255},
        shhtui::datatypes::S_ColorRgb{40,40,40},
        0,
        0
    };

    auto myStyle2 = shhtui::datatypes::S_TextStyle{
        false,
        true,
        true,
        shhtui::datatypes::S_ColorRgb{244,255,32},
        shhtui::datatypes::S_ColorRgb{40,40,40},
        0,
        0
    };

    shhtui::render::pushStyle(myStyle);
    shhtui::render::pushStyle(myStyle2);


    auto myApp = std::make_unique<shhtui::core::C_AppCore>();

    auto myView = std::make_shared<shhtui::core::C_View>("mainView");

    auto testWidget = std::make_shared<shhtui::widgets::C_SimpleLabel>
    (
        shhtui::datatypes::S_Point{1,1},
        shhtui::datatypes::S_Dimension{5,5},
        std::string("ID_01"),
        std::string("Welcome to shhtui!")
    );


    myView->addWidget(testWidget);

    myApp->setView(myView);

    while (myApp->_isRunning)
    {
        myApp->run();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }   
        
    shhtui::render::popStyle();
    return 1;
};