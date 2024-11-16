#include "PlacesController.h"
#include <iostream>

PlacesController::PlacesController()
{  //Rectangle Shapes
    separatorRect.setSize(sf::Vector2f(393.7f, 1001.1f));
    separatorRect.setFillColor(sf::Color(254, 250, 224));
    separatorRect.setPosition(29.4f, 39.4f);

    macRect.setSize(sf::Vector2f(208, 49.1f));
    macRect.setFillColor(sf::Color(255, 49, 49));

    marketRect.setSize(sf::Vector2f(208, 49.1f));
    marketRect.setFillColor(sf::Color(255, 102, 196));

    insRect.setSize(sf::Vector2f(208, 49.1f));
    insRect.setFillColor(sf::Color(94, 23, 235));

    parkRect.setSize(sf::Vector2f(208, 49.1f));
    parkRect.setFillColor(sf::Color(0, 191, 99));

    replacementRect.setSize(sf::Vector2f(208, 49.1f));
    replacementRect.setFillColor(sf::Color(255, 145, 77));

    guacaRect.setSize(sf::Vector2f(208, 49.1f));
    guacaRect.setFillColor(sf::Color(115, 115, 115));

    schoolRect.setSize(sf::Vector2f(208, 49.1f));
    schoolRect.setFillColor(sf::Color(0, 74, 173));

    backRect.setSize(sf::Vector2f(324.0f, 82.0f));
    backRect.setFillColor(sf::Color(212, 163, 115));
    backRect.setPosition(64.3f, 930.9f);

    //Posiciones iniciales
    macRect.setPosition(-300.0f, 200.5f);
    marketRect.setPosition(-300.0f, 295.0f);
    insRect.setPosition(-300.0f, 389.1f);
    parkRect.setPosition(-300.0f, 483.3f);
    replacementRect.setPosition(-300.0f, 577.4f);
    guacaRect.setPosition(-300.0f, 671.5f);
    schoolRect.setPosition(-300.0f, 765.6f);

    // Centrado de textos 
    centerTextInRect(macText, macRect);
    centerTextInRect(marketText, marketRect);
    centerTextInRect(insText, insRect);
    centerTextInRect(parkText, parkRect);
    centerTextInRect(replacementText, replacementRect);
    centerTextInRect(guacaText, guacaRect);
    centerTextInRect(schoolText, schoolRect);

    //Textos
    placesText.setCharacterSize(40);
    placesText.setFillColor(sf::Color(96, 108, 56));
    placesText.setPosition(150, 50.5f); 

    macText.setCharacterSize(17);
    macText.setFillColor(sf::Color::Black);

    marketText.setCharacterSize(17);
    marketText.setFillColor(sf::Color::Black);

    insText.setCharacterSize(17);
    insText.setFillColor(sf::Color::Black);

    parkText.setCharacterSize(17);
    parkText.setFillColor(sf::Color::Black);

    replacementText.setCharacterSize(17);
    replacementText.setFillColor(sf::Color::Black);

    guacaText.setCharacterSize(17);
    guacaText.setFillColor(sf::Color::Black);

    schoolText.setCharacterSize(17);
    schoolText.setFillColor(sf::Color::Black);

    backText.setCharacterSize(19);
    backText.setFillColor(sf::Color::Black);
    backText.setPosition(190.0f, 960.9f);  

    redSprite.setPosition(macRect.getPosition().x - redSprite.getLocalBounds().width - 10, macRect.getPosition().y);
    pinkSprite.setPosition(marketRect.getPosition().x - pinkSprite.getLocalBounds().width - 10, marketRect.getPosition().y);
    purpleSprite.setPosition(insRect.getPosition().x - purpleSprite.getLocalBounds().width - 10, insRect.getPosition().y);
    greenSprite.setPosition(parkRect.getPosition().x - greenSprite.getLocalBounds().width - 10, parkRect.getPosition().y);
    orangeSprite.setPosition(replacementRect.getPosition().x - orangeSprite.getLocalBounds().width - 10, replacementRect.getPosition().y);
    graySprite.setPosition(guacaRect.getPosition().x - graySprite.getLocalBounds().width - 10, guacaRect.getPosition().y);
    blueSprite.setPosition(schoolRect.getPosition().x - blueSprite.getLocalBounds().width - 10, schoolRect.getPosition().y);
}

bool PlacesController::loadResources()
{
    if (!mapTexture.loadFromFile("Lugares.jpg")) {
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

    // Texturas de iconos
    if (!redTexture.loadFromFile("adressRed.jpg")) {
        std::cerr << "Error al cargar adressRed.jpg" << std::endl;
        return false;
    }
    redSprite.setTexture(redTexture);

    if (!pinkTexture.loadFromFile("adressPink.jpg")) {
        std::cerr << "Error al cargar adressPink.jpg" << std::endl;
        return false;
    }
    pinkSprite.setTexture(pinkTexture);

    if (!purpleTexture.loadFromFile("adressPurple.jpg")) {
        std::cerr << "Error al cargar adressPurple.jpg" << std::endl;
        return false;
    }
    purpleSprite.setTexture(purpleTexture);

    if (!greenTexture.loadFromFile("adressGreen.jpg")) {
        std::cerr << "Error al cargar adressGreen.jpg" << std::endl;
        return false;
    }
    greenSprite.setTexture(greenTexture);

    if (!orangeTexture.loadFromFile("adressOrange.jpg")) {
        std::cerr << "Error al cargar adressOrange.jpg" << std::endl;
        return false;
    }
    orangeSprite.setTexture(orangeTexture);

    if (!grayTexture.loadFromFile("adressGray.jpg")) {
        std::cerr << "Error al cargar adressGray.jpg" << std::endl;
        return false;
    }
    graySprite.setTexture(grayTexture);

    if (!blueTexture.loadFromFile("adressBlue.jpg")) {
        std::cerr << "Error al cargar adressBlue.jpg" << std::endl;
        return false;
    }
    blueSprite.setTexture(blueTexture);

    //Texto de botones
    placesText.setFont(breeSerif);
    placesText.setString("Lugares");

    macText.setFont(openSans);
    macText.setString("McDonald´s");

    marketText.setFont(openSans);
    marketText.setString("Mercado");

    insText.setFont(openSans);
    insText.setString("INS");

    parkText.setFont(openSans);
    parkText.setString("Parque");

    replacementText.setFont(openSans);
    replacementText.setString("Repuestos Juanca");

    guacaText.setFont(openSans);
    guacaText.setString("La Guaca");

    schoolText.setFont(openSans);
    schoolText.setString("Escuela");

    backText.setFont(openSans);
    backText.setString("Regresar");

    return true;
}

void PlacesController::render(sf::RenderWindow& window)
{
    window.draw(mapSprite);
    window.draw(separatorRect);
    window.draw(placesText);

    window.draw(macRect);
    window.draw(macText);

    window.draw(marketRect);
    window.draw(marketText);

    window.draw(insRect);
    window.draw(insText);
    
    window.draw(parkRect);
    window.draw(parkText);

    window.draw(replacementRect);
    window.draw(replacementText);

    window.draw(guacaRect);
    window.draw(guacaText);

    window.draw(schoolRect);
    window.draw(schoolText);

    window.draw(backRect);
    window.draw(backText);

    window.draw(redSprite);
    window.draw(pinkSprite);
    window.draw(purpleSprite);
    window.draw(greenSprite);
    window.draw(orangeSprite);
    window.draw(graySprite);
    window.draw(blueSprite);
}

bool PlacesController::handleBackClick(const sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (backRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            return true;
        }
    }
    return false;
}

void PlacesController::animateButtons(float speed) {
    if (macRect.getPosition().x < 122.3f) {
        macRect.move(speed, 0);
        macText.move(speed, 0);
        redSprite.setPosition(macRect.getPosition().x - redSprite.getLocalBounds().width - 10, macRect.getPosition().y);
        centerTextInRect(macText, macRect);
    }

    else if (marketRect.getPosition().x < 122.3f) {
        marketRect.move(speed, 0);
        marketText.move(speed, 0);
        pinkSprite.setPosition(marketRect.getPosition().x - pinkSprite.getLocalBounds().width - 10, marketRect.getPosition().y);
        centerTextInRect(marketText, marketRect);
    }

    else if (insRect.getPosition().x < 122.3f) {
        insRect.move(speed, 0);
        insText.move(speed, 0);
        purpleSprite.setPosition(insRect.getPosition().x - purpleSprite.getLocalBounds().width - 10, insRect.getPosition().y);
        centerTextInRect(insText, insRect);
    }

    else if (parkRect.getPosition().x < 122.3f) {
        parkRect.move(speed, 0);
        parkText.move(speed, 0);
        greenSprite.setPosition(parkRect.getPosition().x - greenSprite.getLocalBounds().width - 10, parkRect.getPosition().y);
        centerTextInRect(parkText, parkRect);
    }

    else if (replacementRect.getPosition().x < 122.3f) {
        replacementRect.move(speed, 0);
        replacementText.move(speed, 0);
        orangeSprite.setPosition(replacementRect.getPosition().x - orangeSprite.getLocalBounds().width - 10, replacementRect.getPosition().y);
        centerTextInRect(replacementText, replacementRect);
    }

    else if (guacaRect.getPosition().x < 122.3f) {
        guacaRect.move(speed, 0);
        guacaText.move(speed, 0);
        graySprite.setPosition(guacaRect.getPosition().x - graySprite.getLocalBounds().width - 10, guacaRect.getPosition().y);
        centerTextInRect(guacaText, guacaRect);
    }

    else if (schoolRect.getPosition().x < 122.3f) {
        schoolRect.move(speed, 0);
        schoolText.move(speed, 0);
        blueSprite.setPosition(schoolRect.getPosition().x - blueSprite.getLocalBounds().width - 10, schoolRect.getPosition().y);
        centerTextInRect(schoolText, schoolRect);
    }
}

void PlacesController::resetPositions() {
    macRect.setPosition(-300.0f, 200.5f);
    marketRect.setPosition(-300.0f, 295.0f);
    insRect.setPosition(-300.0f, 389.1f);
    parkRect.setPosition(-300.0f, 483.3f);
    replacementRect.setPosition(-300.0f, 577.4f);
    guacaRect.setPosition(-300.0f, 671.5f);
    schoolRect.setPosition(-300.0f, 765.6f);

    centerTextInRect(macText, macRect);
    centerTextInRect(marketText, marketRect);
    centerTextInRect(insText, insRect);
    centerTextInRect(parkText, parkRect);
    centerTextInRect(replacementText, replacementRect);
    centerTextInRect(guacaText, guacaRect);
    centerTextInRect(schoolText, schoolRect);

    redSprite.setPosition(macRect.getPosition().x - redSprite.getLocalBounds().width - 10, macRect.getPosition().y);
    pinkSprite.setPosition(marketRect.getPosition().x - pinkSprite.getLocalBounds().width - 10, marketRect.getPosition().y);
    purpleSprite.setPosition(insRect.getPosition().x - purpleSprite.getLocalBounds().width - 10, insRect.getPosition().y);
    greenSprite.setPosition(parkRect.getPosition().x - greenSprite.getLocalBounds().width - 10, parkRect.getPosition().y);
    orangeSprite.setPosition(replacementRect.getPosition().x - orangeSprite.getLocalBounds().width - 10, replacementRect.getPosition().y);
    graySprite.setPosition(guacaRect.getPosition().x - graySprite.getLocalBounds().width - 10, guacaRect.getPosition().y);
    blueSprite.setPosition(schoolRect.getPosition().x - blueSprite.getLocalBounds().width - 10, schoolRect.getPosition().y);
}


void  PlacesController::centerTextInRect(sf::Text& text, const sf::RectangleShape& rect) {
    sf::FloatRect textBounds = text.getLocalBounds();  
    sf::Vector2f rectPos = rect.getPosition();       
    sf::Vector2f rectSize = rect.getSize();       

    text.setPosition(
        rectPos.x + (rectSize.x - textBounds.width) / 2,  // Calcula la nueva posición X
        rectPos.y + (rectSize.y - textBounds.height) / 2   // Calcula la nueva posición Y
    );
}

void PlacesController::handleMouseHover(const sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (backRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        backRect.setFillColor(sf::Color(130, 88, 47));
    }
    else {
        backRect.setFillColor(sf::Color(212, 163, 115));
    }
}


 
