#include "rendering/Display.h"
#include "DEFINITIONS.h"
#include "KEYS.h"
#include <iostream>

namespace Debug {
    namespace
    {
        bool showing;
        sf::Font font;
        std::vector<sf::Text> debugLog;
    }

    void init(sf::Font fnt) {
        font = fnt;
    }

    bool isOpen()
    {
        return showing;
    }

    void close() {
        showing = false;
    }

    void show() {
        showing = true;
    }

    void clear()
    {
        while (!debugLog.empty()) {
            debugLog.pop_back();
        }
    }

    void log(std::string str) {
        //sf::Text text(str, font);
        //text.setFillColor(sf::Color::Black);
        //text.setPosition(sf::Vector2f(10, SCREEN_HEIGHT - (debugLog.size() + 1) * text.getGlobalBounds().height));
        //debugLog.push_back(text);
        std::cout << str << std::endl;
    }

    void draw()
    {
        if (showing) {
            if (!debugLog.empty()) {
                int loc = debugLog.size() + 1;
                for (auto& str : debugLog) {
                    str.setPosition(sf::Vector2f(10, SCREEN_HEIGHT - loc * str.getGlobalBounds().height * 1.1f));
                    Display::draw(str);
                    loc -= 1;
                }
            }
        }
    }
}