#include "../include/core.hpp"

#include <optional>

/**
 * @brief core.cpp defines core.hpp
 * 
 */

namespace shhtui {
namespace core {

bool C_AppCore::run()
{ 
    pollInput();
    update();
    draw();
    return true;
};

bool C_AppCore::draw()
{
    if(!_activeView) {return false;};
    _activeView->draw();
    return true;

}

bool C_AppCore::update()
{
    // if(!_activeView) {return false;};
    // _activeView->update();
    return true;

}

bool C_AppCore::pollInput()
{

    char buffer[64];
    ssize_t n = read(STDIN_FILENO, buffer, sizeof(buffer));

    if (n <= 0) return false;

    for (ssize_t i = 0; i < n; ++i) {
        handleRawByte(buffer[i]);
    }
    return true;
}

bool C_AppCore::onKeyEvent(const datatypes::S_KeyEvent& ev)
{
    if(ev.ch == 'q')
        _isRunning = false;
    if(ev.ch == 'w')
        render::popStyle();
    if (_activeView) {
        _activeView->handleInput(ev);
    }
    return true;
}


bool C_AppCore::handleRawByte(char b)
{
static bool esc = false;
    static std::string seq;

    std::optional<datatypes::S_KeyEvent> ev;

    if (!esc) {
        if (b == '\x1b') {
            esc = true;
            seq.clear();
        } else {
            shhtui::datatypes::S_KeyEvent kev{};
            kev.ctrl = kev.alt = kev.shift = false;

            if (b >= 32 && b <= 126) {
                kev.key = shhtui::datatypes::E_Key::Char;
                kev.ch  = b;
            } else {
                switch (b) {
                    case '\n':
                    case '\r': kev.key = shhtui::datatypes::E_Key::Enter; break;
                    case '\t': kev.key = shhtui::datatypes::E_Key::Tab; break;
                    case 127:  kev.key = shhtui::datatypes::E_Key::Backspace; break;
                    default:   kev.key = shhtui::datatypes::E_Key::Unknown; break;
                }
            }

            ev = kev;
        }
    } else {
        seq += b;

        if (seq.size() >= 2 && seq[0] == '[') {
            shhtui::datatypes::S_KeyEvent kev{};
            kev.ctrl = kev.alt = kev.shift = false;

            switch (seq[1]) {
                case 'A': kev.key = shhtui::datatypes::E_Key::Up;    break;
                case 'B': kev.key = shhtui::datatypes::E_Key::Down;  break;
                case 'C': kev.key = shhtui::datatypes::E_Key::Right; break;
                case 'D': kev.key = shhtui::datatypes::E_Key::Left;  break;
                default:  kev.key = shhtui::datatypes::E_Key::Unknown;
            }

            ev = kev;
            esc = false;
        }
    }

    if (ev) {
        onKeyEvent(*ev);
    }
    return true;
}

bool C_AppCore::setView(std::shared_ptr<core::C_View> newView)
{
    _activeView = newView;
    return true;
}
    
}

}