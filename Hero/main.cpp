#include <cmath>
#include "ResourcePath.hpp"
#include "Bullet.hpp"
#include "Laser.hpp"

float speedAbs = 5;

sf::Vector2f& NormVector (sf::Vector2f& v) {
    float abs = sqrt(v.x * v.x + v.y * v.y);
    v.x = v.x / abs;
    v.y = v.y / abs;
    return v;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    sf::Clock clock;
    sf::Texture texture;
    texture.loadFromFile(resourcePath() + "hero.png");
    sf::Sprite circle(texture);
    circle.setPosition(300, 300);
    bool reachTop = false;
    bool reachBottom = false;
    bool reachRight = false;
    bool reachLeft = false;
    Bullet bullet;
    Laser laser;
    bool shoot = false;
    while (window.isOpen())
    {
        reachTop = (circle.getPosition().y <= 0);
        reachBottom = (circle.getPosition().y >= 500);
        reachRight = (circle.getPosition().x >= 700);
        reachLeft = (circle.getPosition().x <= 0);
        
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Blue);
        sf::Time time = clock.getElapsedTime();
        
        sf::Vector2u ciecleSize = circle.getTexture()->getSize();
        circle.setOrigin(ciecleSize.x / 2, ciecleSize.y / 2);
        
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        sf::Vector2f center = circle.getPosition();
        sf::Vector2f d = sf::Vector2f(mousePosition.x, mousePosition.y) - center;
        const float PI = 3.14159f;
        circle.setRotation(90 + atan2f(d.y, d.x) * 180 / PI);
        sf::Vector2f speed = speedAbs * NormVector(d);
        sf::Vector2f mouseDirection = sf::Vector2f(mousePosition.x, mousePosition.y);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            if (!reachLeft)
                circle.move(-1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            if (!reachRight)
                circle.move(1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if (!reachTop)
            circle.move(0, -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            if (!reachBottom)
            circle.move(0, 1);
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            bullet.SetPosition(circle.getPosition());
            bullet.SetTime(time.asSeconds());
            bullet.SetSpeed(speed);
        }
        if (bullet.IsInBounds()) {
            bullet.SetDrawTime(time.asSeconds());
            bullet.DrawBullet(window);
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
            laser.SetPosition(circle.getPosition());
            laser.SetDirection(mouseDirection);
            laser.DrawLaser(window);
        }
        window.draw(circle);
        window.display();
    }
    return 0;
}
