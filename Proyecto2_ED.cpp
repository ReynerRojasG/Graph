#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "MenuController.h"
#include "MapController.h"
#include "PlacesController.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "WEIZ");

    MenuController menu;
    MapController map;
    PlacesController places;
    sf::Clock clock;
    bool isMapLoaded = false;
    bool isPlacesLoaded = false;
    bool isDikjstraLoaded = false;
    if (!menu.loadResources()) {
        return 1;
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        float deltaTime = clock.restart().asSeconds();
        map.updateCar(deltaTime);
        if (!isMapLoaded && !isPlacesLoaded) {
            menu.handleMouseHover(window);

            if (menu.handleMapClick(window)) {
                if (!map.loadResources()) {
                    return 1;
                }
                isMapLoaded = true;
            }

            if (menu.handleShowPlacesClick(window)) {
                if (!places.loadResources()) {
                    return 1;
                }
                isPlacesLoaded = true;
            }

            window.clear();
            menu.render(window);
            window.display();
        }
        else if (isMapLoaded) {
            map.handleMouseHover(window);
            if (map.handleDikjtraClick(window) && !isDikjstraLoaded) {

                map.requestNodesInput(window);
                isDikjstraLoaded = true;
                std::cout << "Ruta cargada, puedes iniciar!";
            }

            if (isDikjstraLoaded && map.handleStartClick(window)) {
                std::cout << std::endl;

                map.startDijkstra(map.getStartNodeInput(), map.getEndNodeInput());               
                isDikjstraLoaded = false;
            }

            if (map.handleBackClick(window)) {
                isMapLoaded = false;
            }
            window.clear();
            map.render(window);
            window.display();
        }
        else if (isPlacesLoaded) {
            places.animateButtons(2.0f);
            places.handleMouseHover(window);

            if (places.handleBackClick(window)) {
                isPlacesLoaded = false;
                places.resetPositions();
            }
            window.clear();
            places.render(window);
            window.display();
        }
    }

    return 0;
}
