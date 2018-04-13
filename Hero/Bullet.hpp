//
//  Bullet.hpp
//  HomeworkSFML
//
//  Created by Хмурович Никита Андреевич on 24.03.2018.
//  Copyright © 2018 Хмурович Никита Андреевич. All rights reserved.
//

// fixit: используйте #pragma once вместо guard'ов типа ifndef 

#ifndef Bullet_hpp
#define Bullet_hpp

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Bullet {
    // fixit: зачем каждой пуле знать какое-то время ... оно же общее для все пуль ... если у переменной time другое значение, то назовите яснее переменную и добавьте комментарий
    float time_;
    float drawTime_;
    sf::Vector2f speed_;
    // нездорово смешивать отрисовку и логику в одном коде ... но для этого упражнения пусть останется так
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
    
    // fixit: зачем нам здесь отдельно объявлять пустой конструктор
    Bullet () = default;
};

#endif /* Bullet_hpp */
