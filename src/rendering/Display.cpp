#include "Display.h"
#include "../DEFINITIONS.h"
#include "../KEYS.h"
#include "../math/Vector2.h"

namespace Display {
    namespace
    {
        sf::RenderWindow window;
        bool focused = true;
        Vector2<float> loc =  Vector2<float>(0, 0);

        void checkForClose(const sf::Event& e)
        {
            if (e.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (e.type == sf::Event::GainedFocus) {
                focused = true;
            }
            else if (e.type == sf::Event::LostFocus) {
                focused = false;
            }
        }
    }

    void init(const std::string& name)
    {
        window.create({ SCREEN_WIDTH, SCREEN_HEIGHT },
            name,
            sf::Style::Fullscreen);
        window.setVerticalSyncEnabled(true);
    }

    void SetCameraCenter(Vector2<float> newLoc) {
        loc = Vector2<float>(newLoc.x - VIEW_WIDTH /   2, newLoc.y - VIEW_HEIGHT / 2);
    }

    bool isOpen()   
    {
        return window.isOpen();
    }

    bool isFocused() {
        return focused;
    }

    void setCameraLoc(Vector2<float> newLoc) {
        loc = newLoc;
    }

    void resetPos() {
        setCameraLoc(Vector2<float>(0, 0));
        setPos();
    }

    void setPos() {
        sf::View view;
        view.reset(sf::FloatRect(loc.x, loc.y, SCREEN_WIDTH / SCREEN_SCALE_X, SCREEN_HEIGHT / SCREEN_SCALE_X));
        window.setView(view);
    }

    void update()
    {
        window.display();
    }

    void close() {
        window.close();
    }

    void clear(const sf::Color& colour)
    {
        window.clear(colour);
    }

    void draw(const sf::Drawable& drawable)
    {
        window.draw(drawable);
    }

    void pollEvents()
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            checkForClose(e);
        }
    }
}