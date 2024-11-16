#pragma once
#include <SFML/Graphics.hpp>
class PlacesController
{
private:
    sf::Texture mapTexture;
    sf::Sprite mapSprite;
    sf::Font breeSerif;
    sf::Font openSans;
    
    sf::Text macText;
    sf::Text marketText;
    sf::Text insText;
    sf::Text parkText;
    sf::Text replacementText;
    sf::Text guacaText;
    sf::Text schoolText;

    sf::Text backText;

    sf::RectangleShape separatorRect;

    sf::RectangleShape macRect;
    sf::RectangleShape marketRect;
    sf::RectangleShape insRect;
    sf::RectangleShape parkRect;
    sf::RectangleShape replacementRect;
    sf::RectangleShape guacaRect;
    sf::RectangleShape schoolRect;
    sf::RectangleShape backRect;

    sf::Texture redTexture, pinkTexture, purpleTexture, greenTexture, orangeTexture, grayTexture, blueTexture;
    sf::Sprite redSprite, pinkSprite, purpleSprite, greenSprite, orangeSprite, graySprite, blueSprite;
public:
    sf::Text placesText;
    PlacesController();
    bool loadResources();
    void render(sf::RenderWindow& window);
    bool handleBackClick(const sf::RenderWindow& window);
    void animateButtons(float speed);
    void resetPositions();
    void centerTextInRect(sf::Text& text, const sf::RectangleShape& rect);
    void handleMouseHover(const sf::RenderWindow& window);
};

