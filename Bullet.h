#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
#include "Player.h"

class Bullet {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f speed;
	Player player;
public:
	Bullet(sf::Vector2f pos, sf::Vector2f fspeed) {
		texture.loadFromFile(Bullet_File_Name);
		sprite.setTexture(texture);
		sprite.setPosition(pos);
		speed = fspeed;
	}
	void update() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			sprite.move(speed);
		}
		sf::Vector2f pos = player.getPosition();
	}
	sf::Sprite getSprite() { return sprite; }
};