// widgets.hpp
#ifndef SHHTUI_WIDGETS_HPP
#define SHHTUI_WIDGETS_HPP

#include <tuple>
#include <string>
#include <functional>

namespace shhtui::widgets {

    struct Widget {
    public:
        Widget(std::tuple<int,int> position, std::tuple<int,int> size)
            : _position(position), _size(size) {};
    
        virtual ~Widget() {}; 

        virtual bool draw(bool isFocused = 0) {return -1;};
        virtual bool handleInput(int key) {return -1;};
        virtual bool update() {return -1;};

    protected:
        std::tuple<int,int> _position;
        std::tuple<int,int> _size;

    };

    class Label : public Widget {
    public:
        Label(std::tuple<int,int> position, std::string text);
        bool draw(bool isFocused = 0) override;
        bool handleInput(int key) override;

        std::tuple<int,int> _position;
        std::string _text;
    };

    class Button : public Widget {
    public:
        Button(std::tuple<int,int> position, std::tuple<int,int> size, std::string text);
        bool onClick(std::function<bool()> callback);
        bool draw(bool isFocused = 0) override;
        bool handleInput(int key) override;

        std::tuple<int,int> _position;
        std::tuple<int,int> _size;
        std::string _text;

    };

}

#endif