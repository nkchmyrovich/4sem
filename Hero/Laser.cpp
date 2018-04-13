//
//  Laser.cpp
//  HomeworkSFML
//
//  Created by Хмурович Никита Андреевич on 24.03.2018.
//  Copyright © 2018 Хмурович Никита Андреевич. All rights reserved.
//

#include "Laser.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

void Laser::SetPosition(const sf::Vector2f& position) {
    position_ = position;
}

// fixit: const sf::Vector2f&
void Laser::SetDirection(sf::Vector2f& direction) {
    direction_ = direction;
}

void Laser::DrawLaser(sf::RenderWindow& window) {
    // fixit: сидя по тому, как вы используете переменные position и direction, название по крайней мере у одной из них выбрано не очень понятно
    sf::Vertex line[] =
    {
        sf::Vertex(position_),
        sf::Vertex(direction_)
    };
    window.draw(line, 2, sf::Lines);
}
