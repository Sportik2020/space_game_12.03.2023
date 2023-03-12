#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
#include <vector>
#include "meteor.h"
#include "Player.h"
#include "Bullet.h"

class Game {
private:
	sf::RenderWindow window;
	std::vector<Meteor*> meteors;
	Player player;
	Bullet bul;
public:
	void spawnMeteors(size_t n) {
		for (int i = 0; i < n; i++) {
			int num = rand() % 4 + 1;
			std::string fileName = "images\\spaceMeteors_00" + std::to_string(num) + ".png";
			Meteor::MeteorSize size = (Meteor::MeteorSize)(rand() % 3);
			float x = rand() % 301 - 300.f;
			int choice = rand() % 10000;
			if (choice < 5000)x += 1200.f;
			float y = rand() % 301 - 300.f;
			choice = rand() % 10000;
			if (choice < 5000)y += 1200.f;
			float speedx = rand() % 11 - 5.f;
			float speedy = rand() % 11 - 5.f;
			Meteor* m = new Meteor(fileName, size, sf::Vector2f{ x,y }, sf::Vector2f{ speedx, speedy });
			meteors.push_back(m);
		}
	}
	Game() {
		window.create(sf::VideoMode{ (size_t)WINDOW_WIDTH, (size_t)WINDOW_HEIGHT }, WINDOW_TITLE);
		window.setFramerateLimit(FPS);
		spawnMeteors(20);
		
	}

	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed) window.close();
	}

	void update() {
		for (int i = 0; i < meteors.size(); i++) {
			meteors.at(i)->update();
		}
		player.update();
		bul.update();
	}

	void checkCollisions() {}

	void draw() {
		window.clear();
		for (int i = 0; i < meteors.size(); i++) {
			window.draw(meteors.at(i)->getSprite());
		}
		window.draw(player.getSprite());
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			window.draw(bul.getSprite());
		}
		window.display();
	}

	void play() {
		while (window.isOpen()) {
			checkEvents();
			update();
			checkCollisions();
			draw();
		}
	}
};