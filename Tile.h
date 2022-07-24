#pragma once
#include "json.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Settings.h"
#include <unordered_map>
using json = nlohmann::json;

enum class TileNames {
	DEEP_WATER,
	BASIC_GROUND,
	FOREST_GROUND,
	SHALLOW_WATER,
	BASIC_GRASS,
	BASIC_WALL
};

inline const std::unordered_map<std::string, TileNames> tileString{
	{"basic_ground", TileNames::BASIC_GROUND},
	{"basic_wall", TileNames::BASIC_WALL},
	{"basic_grass", TileNames::BASIC_GRASS},
	{"shallow_water", TileNames::SHALLOW_WATER},
	{"deep_water", TileNames::DEEP_WATER},
	{"forest_ground", TileNames::FOREST_GROUND}
};

enum class DecorTiles {
	PEBBLES_1,
	PEBBLES_2,
	FLOWERS_1,
	FLOWERS_2,
	WATER_LILY_1,
	CATTAIL_1,
	TREE_1
};

inline const std::unordered_map<std::string, DecorTiles> decorString{
	{"pebbles_1.png", DecorTiles::PEBBLES_1},
	{"pebbles_2.png", DecorTiles::PEBBLES_2},
	{"flowers_1.png", DecorTiles::FLOWERS_1},
	{"flowers_2.png", DecorTiles::FLOWERS_2},
	{"water_lily_1.png", DecorTiles::WATER_LILY_1},
	{"cattail_1.png", DecorTiles::CATTAIL_1},
	{"tree_1.png", DecorTiles::TREE_1}
};

class Tile {
public:
	Tile(json j);
	bool getTraversable();
	const std::vector<std::string>& getPossibleDecorations();
	std::string getName();
	void print();
private:
	bool isTraversable;
	std::vector<std::string> possibleDecorations;
	std::string name;


};

