#include "Game.h"
#include "Settings.h"
#include <SFML/Graphics.hpp>

//#include "json.hpp"
//#include <fstream>
//using json = nlohmann::json;



sf::Vector2i Settings::WINDOW_SIZE = sf::Vector2i(800, 600);
sf::Vector2i Settings::CHUNK_SIZE = sf::Vector2i(28, 21);
int Settings::TILE_SIZE = 32;
int Settings::TILE_SCALE = 2;
std::vector<long long> Settings::SEED = std::vector<long long>();

int main() {

	//json jsonfile;

	//json testVector;
	//testVector["chunkPos"] = { 1, 2 };

	//json testHero;
	//testHero["pos"] = { 2, 43 };
	//testHero["name"] = "Okka";


	//jsonfile["testVector"] = testVector;
	//jsonfile["testHero"] = testHero;


	////loading into
	//std::ofstream file("Save.json");
	//file << jsonfile;
	//file.close();
	std::cout << "jebac git 123" << std::endl;
	std::cout << "if this doesn't work i'll brick my pipi" << std::endl;
	std::cout << "aaaaaaaaaaaaaaaaaa" << std::endl;
	Settings::updateSettings();
	//std::cout << std::format("a{}", 42);
	Game game;
	game.Run();

	return 0;
}