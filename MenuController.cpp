#include "MenuController.h"

MenuController::MenuController() {
    //Rectangle Shapes
    chargeMapRect.setSize(sf::Vector2f(324, 82));
    chargeMapRect.setFillColor(sf::Color(254, 250, 224));
    chargeMapRect.setPosition(785, 244); //MATHS DE CENTRADO poner -100px de ancho y -30px de alto

    showPlacesRect.setSize(sf::Vector2f(324, 82));
    showPlacesRect.setFillColor(sf::Color(254, 250, 224));
    showPlacesRect.setPosition(785, 403);

    //Textos
    appName.setCharacterSize(60);
    appName.setFillColor(sf::Color(254, 250, 224));
    appName.setPosition(869, 60);

    chargeMap.setCharacterSize(19);
    chargeMap.setFillColor(sf::Color::Black);
    chargeMap.setPosition(885, 274);

    showPlaces.setCharacterSize(19);
    showPlaces.setFillColor(sf::Color::Black);
    showPlaces.setPosition(865, 433);
}

bool MenuController::loadResources() {
    if (!texture.loadFromFile("Fondo.jpg")) {
        std::cerr << "Error al cargar la imagen." << std::endl;
        return false;
    }
    sprite.setTexture(texture);

    if (!breeSerif.loadFromFile("BreeSerif.ttf")) {
        std::cerr << "Error cargando la fuente BreeSerif." << std::endl;
        return false;
    }
    if (!openSans.loadFromFile("OpenSans.ttf")) {
        std::cerr << "Error cargando la fuente OpenSans." << std::endl;
        return false;
    }

    appName.setFont(breeSerif);
    appName.setString("WEIZ");

    chargeMap.setFont(openSans);
    chargeMap.setString("Cargar Mapa");

    showPlaces.setFont(openSans);
    showPlaces.setString("Lugares disponibles");

    return true;
}

void MenuController::handleMouseHover(const sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    if (chargeMapRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        chargeMapRect.setFillColor(sf::Color(198, 189, 120));
    }
    else {
        chargeMapRect.setFillColor(sf::Color(254, 250, 224));
    }

    if (showPlacesRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        showPlacesRect.setFillColor(sf::Color(198, 189, 120));
    }
    else {
        showPlacesRect.setFillColor(sf::Color(254, 250, 224));
    }
}

bool MenuController::handleMapClick(const sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (chargeMapRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            return true; // Si se clickeo el boton de cargar mapa
        }
    }
    return false;
}

bool MenuController::handleShowPlacesClick(const sf::RenderWindow& window)
{
    if (showPlacesRect.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            return true; 
        }
    }
    return false;
}

void MenuController::render(sf::RenderWindow& window) {
    window.draw(sprite);
    window.draw(appName);

    window.draw(chargeMapRect);
    window.draw(showPlacesRect);

    window.draw(chargeMap);
    window.draw(showPlaces);
}
