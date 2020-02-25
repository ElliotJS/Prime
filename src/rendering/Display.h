#pragma once

#include <cstdint>
#include <SFML/Graphics.hpp>
#include "../DEFINITIONS.h"
#include "../math/Vector2.h"

namespace Display {
    void init(const std::string& name);

    bool isOpen();
    bool isFocused();

    void resetPos();
    void setPos();
    void update();
    void clear(const sf::Color& colour);

    void SetCameraCenter(Vector2<float> newLoc);

    void close();
    void pollEvents();

    void draw(const sf::Drawable& drawable);
}