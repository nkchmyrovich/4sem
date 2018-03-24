//
//  Laser.hpp
//  HomeworkSFML
//
//  Created by Хмурович Никита Андреевич on 24.03.2018.
//  Copyright © 2018 Хмурович Никита Андреевич. All rights reserved.
//

#ifndef Laser_hpp
#define Laser_hpp

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Laser {
    sf::Vector2f position_;
    sf::Vector2f direction_;
public:
    void SetPosition (const sf::Vector2f& position);
    void SetDirection (sf::Vector2f& direction);
    void DrawLaser (sf::RenderWindow& window);
    Laser () = default;
};


#endif /* Laser_hpp */
