#pragma once
#include "Node.h"
#include "Edge.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <queue>
#include <unordered_map>
#include <iostream>
#include <climits> 
#include "Car.h"
class Graph {
private:
    std::vector<Node> nodes;
    std::vector<Edge> edges;
    float price;

public:
    Graph();
    void addNode(float x, float y, const std::string& name = "");
    void draw(sf::RenderWindow& window) const;
    void addEdge(Node* startNode, Node* endNode);

    float calculateDistance(Node* node1, Node* node2) const;
    Node* findNodeByName(const std::string& name) const;
    float calculateCost(float distance);
    void Dijkstra(const std::string& startName, const std::string& endName, Car& car);
    void initializeGraph();
    float getPrice();
    void BFS(); 
    

};
