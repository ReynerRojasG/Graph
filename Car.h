#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <iostream>
class Car {
private:
    sf::Sprite carSprite;
    sf::Texture carTexture;
    float speed;
    std::vector<sf::Vector2f> path;
    size_t currentTargetIndex;
    bool moving;

public:
    Car(float width, float height, sf::Color color, float speed);
    void setPath(const std::vector<sf::Vector2f>& nodes);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
};
