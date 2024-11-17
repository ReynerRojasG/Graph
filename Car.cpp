#include "Car.h"

Car::Car(float width, float height, sf::Color color, float speed)
    : speed(speed), currentTargetIndex(0), moving(false) {

    if (!carTexture.loadFromFile("right.png")) {
        std::cerr << "Error al cargar la imagen 'right.png'" << std::endl;
    }
    else {
        carSprite.setTexture(carTexture);
        carSprite.setOrigin(width / 2.0f, height / 2.0f);
    }

    float scaleX = width / carTexture.getSize().x;
    float scaleY = height / carTexture.getSize().y;
    scaleX *= 1.2f;
    scaleY *= 1.2f;
    carSprite.setScale(scaleX, scaleY);
}

void Car::setPath(const std::vector<sf::Vector2f>& nodes) {
    path = nodes;
    if (!path.empty()) {
        carSprite.setPosition(path[0]);
    }
    currentTargetIndex = 1;
    moving = true;
}

void Car::update(float deltaTime) {
    if (!moving || currentTargetIndex >= path.size()) return;

    sf::Vector2f currentPosition = carSprite.getPosition();
    sf::Vector2f targetPosition = path[currentTargetIndex];

    sf::Vector2f direction = targetPosition - currentPosition;
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance != 0) direction /= distance;

    float step = speed * deltaTime;
    if (step >= distance) {
        carSprite.setPosition(targetPosition);
        currentTargetIndex++;
        if (currentTargetIndex >= path.size()) moving = false;
    }
    else {
        carSprite.move(direction * step);
    }
}

void Car::draw(sf::RenderWindow& window) {
    window.draw(carSprite);
}

