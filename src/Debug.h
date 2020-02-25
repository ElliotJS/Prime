#pragma once

#include <cstdint>
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"

namespace Debug {
    void init(sf::Font fnt);

    bool isOpen();

    void clear(const sf::Color& colour);

    void show();
    void close();
    
    void log(std::string str);

    void draw();
}