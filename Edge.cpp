#include "Edge.h"
#include <cmath>

Edge::Edge(Node* start, Node* end)
    : startNode(start), endNode(end), lineColor(sf::Color::Red) {
    sf::Vector2f direction = end->getPosition() - start->getPosition();
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    float thickness = 3.0f;
    rectangle.setSize(sf::Vector2f(length, thickness));  
    rectangle.setFillColor(lineColor);

    rectangle.setPosition(start->getPosition());

    float angle = std::atan2(direction.y, direction.x) * 180.0f / 3.14159265f;
    rectangle.setRotation(angle);
}

void Edge::draw(sf::RenderWindow& window) const {
    window.draw(rectangle);
}

Node* Edge::getStartNode() const {
    return startNode;
}

Node* Edge::getEndNode() const {
    return endNode;
}

void Edge::setColor(const sf::Color& color) {
    lineColor = color;
    rectangle.setFillColor(color);
}
