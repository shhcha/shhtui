// app.cpp
#include "../include/app.hpp"
#include "../include/renderer.hpp"

#include <cstdio>
#include <set>
#include <string>
#include <unistd.h>

namespace shhtui::app {

/// C_View

    //Constructor
    C_View::C_View(std::string id)
        : _name(id) {};
    
    bool C_View::addWidget(widgets::Widget* w) {
        if (!w) return 0;
        _widgets.push_back(w);
        return 1;
    }

    bool C_View::update() {
        for (auto w : _widgets)
            w->update();
        return 1 ;
    }

    bool C_View::handleInput(int key) {
        if (_widgets.empty()) return 1;

        // handle focus keys
        if (key == '\t') { // Tab cycles focus
            _focused = (_focused + 1) % _widgets.size();
        }

        _widgets[_focused]->handleInput(key);
        return 1;
    }

    bool C_View::draw() {
        for (int i=0;i<=_widgets.size()-1;i++)
        {
            auto w = _widgets[i];
            if (i==_focused)
                w->draw(1);
            else
                w->draw(0);
        }   
        return 1;
    }

/// C_Application

    C_Application::C_Application() {
        _running = 1;
    };

    bool C_Application::setActiveView(C_View* v)
    {
        _activeView = v;
        return 1;
    }

    bool C_Application::run() {
        while (_running) {
            pollInput();
            update();
            draw();
            usleep(16000);                // 60 FPS
        }
        return 1;
    }

    bool C_Application::pollInput() {
        if (!_activeView) return -1;

        // non-blocking read
        char ch = 0;
        int result = read(STDIN_FILENO, &ch, 1);

        if (result > 0 && ch == 113) { // Quit on Q
            requestExit();
        }
        if (result == 1) {
            _activeView->handleInput(ch);
        }
        return 1;
    }

    bool C_Application::update() {
        if (_activeView)
            _activeView->update();
        return 1;
    }

    bool C_Application::draw() {
        renderer::clearScreen();
        if (_activeView)
            _activeView->draw();
        shhtui::renderer::refreshScreen();
        return 1;    
    }
        

    bool C_Application::requestExit() {
        _running = false;
        return 1;
    }

    bool C_Application::isRunning() const {
        return _running;
    }
// C_Application
}


