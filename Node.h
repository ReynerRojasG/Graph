#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Node {
private:
    sf::Vector2f position;
    std::string name;
    sf::CircleShape shape;

public:
    Node(float x, float y, const std::string& name = "");

    const sf::Vector2f& getPosition() const;
    const std::string& getName() const;
    sf::CircleShape getDrawable() const;
};
