#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class MenuController {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Font breeSerif;
    sf::Font openSans;
    sf::Text appName;
    sf::Text chargeMap;
    sf::Text showPlaces;

    sf::RectangleShape chargeMapRect;
    sf::RectangleShape showPlacesRect;
public:
    MenuController();
    bool loadResources();
    void handleMouseHover(const sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    bool handleMapClick(const sf::RenderWindow& window);
    bool handleShowPlacesClick(const sf::RenderWindow& window);
};
