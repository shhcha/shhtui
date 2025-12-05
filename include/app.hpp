// app.hpp
#ifndef SHHTUI_APP_HPP
#define SHHTUI_APP_HPP

#include "widgets.hpp"


namespace shhtui::app {

    class C_View {
    public:
        C_View(std::string id);
        
        bool addWidget(widgets::Widget* w);
        bool update();
        bool handleInput(int key);
        bool draw();

        std::string _name;
        std::vector<shhtui::widgets::Widget*> _widgets;
        int _focused = 0;

    };

    class C_Application {
    public:
        C_Application();

        bool setActiveView(C_View* v);
        bool requestExit();
        bool isRunning() const;
        bool update();
        
        bool pollInput();
        bool run();
        bool draw();

        bool _running;
        C_View* _activeView;
    };

}

#endif