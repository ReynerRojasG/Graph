#pragma once
#include "Node.h"
#include <SFML/Graphics.hpp>

class Edge {
private:
    Node* startNode;
    Node* endNode;
    sf::RectangleShape rectangle;  
    sf::Color lineColor;

public:
    Edge(Node* start, Node* end);

    void draw(sf::RenderWindow& window) const;

    Node* getStartNode() const;
    Node* getEndNode() const;
    void setColor(const sf::Color& color);
};
