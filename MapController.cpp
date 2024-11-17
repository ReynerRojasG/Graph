#include "MapController.h"

MapController::MapController():car(50.0f, 25.0f, sf::Color::Red, 100.0f), isCarVisible(false) {
    //Rectangle Shapes
    separatorRect.setSize(sf::Vector2f(393.7f, 1001.1f));
    separatorRect.setFillColor(sf::Color(254, 250, 224));
    separatorRect.setPosition(29.4f, 39.4f);

    dijkstraRect.setSize(sf::Vector2f(324.0f, 82.0f));
    dijkstraRect.setFillColor(sf::Color(188, 108, 37));
    dijkstraRect.setPosition(64.3f, 142.9f);

    startRect.setSize(sf::Vector2f(324.0f, 82.0f));
    startRect.setFillColor(sf::Color(212, 163, 115));
    startRect.setPosition(64.3f, 481.3f);

    backRect.setSize(sf::Vector2f(324.0f, 82.0f));
    backRect.setFillColor(sf::Color(212, 163, 115));
    backRect.setPosition(64.3f, 930.9f);

    //Textos
    algorithmsText.setCharacterSize(40);
    algorithmsText.setFillColor(sf::Color(96, 108, 56));
    algorithmsText.setPosition(125.0f, 50.5f);

    selectText.setCharacterSize(40);
    selectText.setFillColor(sf::Color(96, 108, 56));
    selectText.setPosition(125.0f, 392.6f);

    dijkstraText.setCharacterSize(19);
    dijkstraText.setFillColor(sf::Color::Black);
    dijkstraText.setPosition(190.0f, 172.9f);

    startText.setCharacterSize(19);
    startText.setFillColor(sf::Color::Black);
    startText.setPosition(190.0f, 511.3f);

    backText.setCharacterSize(19);
    backText.setFillColor(sf::Color::Black);
    backText.setPosition(190.0f, 960.9f);

    costText.setCharacterSize(23);
    costText.setFillColor(sf::Color::White);
    costText.setPosition(1400.0f, 98.9f);

    priceText.setCharacterSize(23);
    priceText.setFillColor(sf::Color::White);
    priceText.setPosition(1624.2f, 98.9f);

    graph.initializeGraph();
}


bool MapController::loadResources() {
    if (!mapTexture.loadFromFile("Mapa.jpg")) {
        std::cerr << "Error al cargar la imagen Mapa." << std::endl;
        return false;
    }
    mapSprite.setTexture(mapTexture);

    if (!breeSerif.loadFromFile("BreeSerif.ttf")) {
        std::cerr << "Error cargando la fuente BreeSerif." << std::endl;
        return false;
    }
    if (!openSans.loadFromFile("OpenSans.ttf")) {
        std::cerr << "Error cargando la fuente OpenSans." << std::endl;
        return false;
    }

    algorithmsText.setFont(breeSerif);
    algorithmsText.setString("Algoritmos");

    selectText.setFont(breeSerif);
    selectText.setString("Seleccionar");

    dijkstraText.setFont(openSans);
    dijkstraText.setString("Dijkstra");


    startText.setFont(openSans);
    startText.setString("Iniciar ruta");

    backText.setFont(openSans);
    backText.setString("Regresar");

    costText.setFont(openSans);
    costText.setString("Costo en Colones:");

    return true;
}

void MapController::handleMouseHover(const sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    if (dijkstraRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        dijkstraRect.setFillColor(sf::Color(209, 147, 92)); 
    }
    else {
        dijkstraRect.setFillColor(sf::Color(188, 108, 37)); 
        
    }
    if (startRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        startRect.setFillColor(sf::Color(130, 88, 47));
    }
    else {
        startRect.setFillColor(sf::Color(212, 163, 115));
    }

    if (backRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        backRect.setFillColor(sf::Color(130, 88, 47));
    }
    else {
        backRect.setFillColor(sf::Color(212, 163, 115));
    }
}

bool MapController::handleBackClick(const sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (backRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            return true; 
        }
    }
    return false;
}

bool MapController::handleDikjtraClick(const sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (dijkstraRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            return true;
        }
    }
    return false;
}

bool MapController::handleStartClick(const sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (startRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            return true;
        }
    }
    return false;
}

void MapController::render(sf::RenderWindow& window) {
    window.draw(mapSprite);
    window.draw(separatorRect);
   
    window.draw(algorithmsText);
    window.draw(selectText);
    window.draw(dijkstraRect);
    window.draw(dijkstraText);
    window.draw(startRect);
    window.draw(startText);
    window.draw(backRect);
    window.draw(backText);
    window.draw(costText);
    window.draw(priceText);
    graph.draw(window);
    if (isCarVisible) {
        car.draw(window);
    }
}

void MapController::addNodeToGraph(float x, float y, const std::string& name)
{
    graph.addNode(x, y, name);
}

void MapController::requestNodesInput(sf::RenderWindow& window) {
    std::cout << std::endl;
    std::cout << "Por favor ingrese el nodo de inicio: ";
    std::cin >> startNodeInput;
    std::cout << "Por favor ingrese el nodo final: ";
    std::cin >> endNodeInput;
}

void MapController::startDijkstra(const std::string& startNode, const std::string& endNode) {
    std::cout << "Iniciando Dijkstra desde " << startNode << " hasta " << endNode << std::endl;
    graph.Dijkstra(startNode, endNode, car);
    isCarVisible = true;
    priceText.setFont(openSans);
    float price = graph.getPrice();

    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << price; 
    std::string price_str = stream.str();

    priceText.setString(price_str);
}

void MapController::updateCar(float deltaTime)
{
    car.update(deltaTime);
}

std::string MapController::getStartNodeInput(){
    return startNodeInput;
}
std::string MapController::getEndNodeInput() {
    return endNodeInput;
}
