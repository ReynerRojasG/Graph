#include "Node.h"

Node::Node(float x, float y, const std::string& name)
    : position(x, y), name(name) {
    shape.setRadius(5.0f);
    shape.setPosition(x - shape.getRadius(), y - shape.getRadius());
    shape.setFillColor(sf::Color::Magenta);
}

const sf::Vector2f& Node::getPosition() const {
    return position;
}

const std::string& Node::getName() const {
    return name;
}

sf::CircleShape Node::getDrawable() const {
    return shape;
}
