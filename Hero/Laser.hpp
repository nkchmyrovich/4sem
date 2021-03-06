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
    
    /* Смотрите, зачем нужно иногда явно прописывать дефолтный конструктор:
    
    1) если не объявить никакой конструктор, то компилятор сам сгенерит пустой конструктор <-> дефолтный
    2) если объявить самим какой-нибудь конструтор, например Laser(const Color& color), то дефолтный уже генериться не будет
    а вот как раз если он все-таки нужен, то дополнительно сами это указываем Laser() = default;
    
    Ваша ситуация похожа на случай 1) -> лучше просто ничего не писать
    */
    Laser () = default;
};


#endif /* Laser_hpp */
