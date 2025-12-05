// widgets.cpp
#include "../include/widgets.hpp"
#include "../include/renderer.hpp"
#include <functional>

namespace shhtui::widgets {

//Widget 




/// Label

    Label::Label(std::tuple<int,int> position, std::string text) 
        : Widget(position, {static_cast<int>(text.size()), 1}),  // width = text length, height = 1
      _text(text)
    {};

    bool Label::draw(bool isFocused) {
        renderer::_drawRawText(_text,  _position);
        return 1;
    }

    bool Label::handleInput(int key) {
        return 1;
    }

// Button

    /// Create a Button Widget
    /// Size should be {r,c}, where 'c' is odd, (eg. 3,5) to ensure centering of label
    ///
    Button::Button(std::tuple<int,int> position, std::tuple<int,int> size, std::string label)
        : Widget(position, size), _text(label)
    {
        //Check Label Width
        if (_text.size() > static_cast<size_t>(std::get<1>(size) - 2)) {
            _text = _text.substr(0, std::get<1>(size) - 2);
        }

    };

    bool Button::onClick(std::function<bool()> callback)
    {
        return callback();
    }
    
    bool Button::draw(bool isFocused) {
        if (isFocused)
        renderer::_drawBox( Widget::_position,
                            Widget::_size, 
                            "\033[31;1m" );
        else
         renderer::_drawBox( Widget::_position,
                            Widget::_size, 
                            "\033[0m" );

        // Centering text in box
        int s = int(_text.size()/2);
        int r = std::get<0>(Widget::_position) + int(std::get<0>(Widget::_size)/2);
        int c = std::get<1>(Widget::_position) + int(std::get<1>(Widget::_size)/2);

        c -= s;

        renderer::_drawRawText(_text, {r,c});
        return 1;
    }

    bool Button::handleInput(int key) {
        if (key == 119)
            renderer::_drawRawText("cLIKED", {2,2});
        return 1;
    }

}
