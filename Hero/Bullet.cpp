//
//  Bullet.cpp
//  HomeworkSFML
//
//  Created by Хмурович Никита Андреевич on 24.03.2018.
//  Copyright © 2018 Хмурович Никита Андреевич. All rights reserved.
//

#include "Bullet.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

float bulletSize = 10;

void Bullet::Move (float time) {
    position_.x += speed_.x * (time - time_);
    position_.y += speed_.y * (time - time_);
    bullet_.move(position_);
}


void Bullet::SetPosition(const sf::Vector2f& position) {
    position_ = position;
}

void Bullet::CreateBullet() {
    bullet_ = sf::CircleShape (bulletSize);
    bullet_.setFillColor (sf::Color::Red);
}

void Bullet::SetTime (float time) {
    time_ = time;
}

void Bullet::SetDrawTime(float time) {
    drawTime_ = time;
}

void Bullet::SetSpeed (sf::Vector2f& speed) {
    speed_ = speed;
}

void Bullet::DrawBullet (sf::RenderWindow& window) {
    CreateBullet();
    Move(drawTime_);
    window.draw(bullet_);
}

bool Bullet::IsInBounds() {
    bool reachTop = (position_.y <= 0);
    bool reachBottom = (position_.y >= 500);
    bool reachRight = (position_.x >= 700);
    bool reachLeft = (position_.x <= 0);
    if (!reachTop && !reachBottom && !reachLeft && !reachRight) {
        return true;
    }
    return false;
    
}
