#pragma once
#include <cmath>
#include "settings.h"
class Player {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float angle;
	float speed, speedx, speedy;
public:
	Player() {
		texture.loadFromFile(Player_File_Name);
		sprite.setTexture(texture);
		sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		sprite.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		angle = 0;
	}
	void update() {
		speed = 1.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			angle -= 3;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			angle += 3;
		}
		sprite.setRotation(angle);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			speed += 10.f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			speed = 0.f;
		}
		sprite.setRotation(angle);
		speedx = speed * sin(angle * PI / 180);
		speedy = speed * cos(angle * PI / 180);
		sprite.move(speedx, speedy);
	}
	sf::Sprite getSprite() { return sprite; }
};
