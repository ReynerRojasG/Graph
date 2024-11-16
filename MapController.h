#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Graph.h"
#include <iostream>
#include <iomanip> 
#include <sstream>
class MapController {
private:
    Graph graph;
    sf::Texture mapTexture;
    sf::Sprite mapSprite;
    sf::Font breeSerif;
    sf::Font openSans;
    //En el rectangulo separador
    sf::Text algorithmsText;
    sf::Text selectText;
    sf::Text dijkstraText;
    sf::Text startText;
    sf::Text backText;

    sf::Text costText;
    sf::Text priceText;

    sf::RectangleShape separatorRect;

    sf::RectangleShape dijkstraRect;
    sf::RectangleShape startRect;
    sf::RectangleShape backRect;

    std::string startNodeInput;
    std::string endNodeInput;
public:
    MapController();
    bool loadResources();
    void handleMouseHover(const sf::RenderWindow& window);
    bool handleBackClick(const sf::RenderWindow& window);
    bool handleDikjtraClick(const sf::RenderWindow& window);
    bool handleStartClick(const sf::RenderWindow& window);
    void addNodeToGraph(float x, float y, const std::string& name);
    void render(sf::RenderWindow& window);
    void requestNodesInput(sf::RenderWindow& window);
    void startDijkstra(const std::string& startNode, const std::string& endNode);
    std::string getStartNodeInput();
    std::string getEndNodeInput();
};