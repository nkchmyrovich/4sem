//
//  Bullet.hpp
//  HomeworkSFML
//
//  Created by Хмурович Никита Андреевич on 24.03.2018.
//  Copyright © 2018 Хмурович Никита Андреевич. All rights reserved.
//

#ifndef Bullet_hpp
#define Bullet_hpp

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Bullet {
    float time_;
    float drawTime_;
    sf::Vector2f speed_;
    sf::CircleShape bullet_;
    sf::Vector2f position_;
public:
    void Move (float time);
    void SetPosition (const sf::Vector2f& position);
    void CreateBullet ();
    void DrawBullet (sf::RenderWindow& window);
    void SetTime (float time);
    void SetDrawTime (float time);
    void SetSpeed (sf::Vector2f& speed);
    bool IsInBounds ();
    Bullet () = default;
};

#endif /* Bullet_hpp */
