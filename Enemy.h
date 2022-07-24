#pragma once
#include <SFML/Graphics.hpp>
#include "Settings.h"
#include <random>
#include <iostream>
#include "World.h"

#include "json.hpp"
#include <fstream>
using json = nlohmann::json;

//class World;
class Enemy : public sf::Drawable {
public:
	Enemy(const sf::Texture& texture, sf::Vector2i position, std::shared_ptr<World> world);
	Enemy(const sf::Texture& texture, sf::Vector2i position, std::shared_ptr<World> world, json saveData);
	void move(sf::Vector2i dir);
	void takeTurn();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Vector2i getPosition();
	json serialize();
private:
	sf::Vector2i position;
	const sf::Texture* texture;
	std::shared_ptr<World> world;
};

