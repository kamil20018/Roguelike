#include "TileLoader.h"

void TileLoader::loadTilesToContext(std::shared_ptr<Context>& context) {

	std::ifstream reader("Tiles.json");
	json j;
	reader >> j;
	reader.close();

	std::unordered_map<TileNames, sf::Texture> tileTextureMap;
	std::unordered_map<DecorTiles, sf::Texture> decorTextureMap;

	for (const auto& tile : j) {
		std::string tileTexturePath = "Resources/Textures/Tiles/";
		tileTexturePath.append(tile["file"]);
		sf::Texture texture;
		texture.loadFromFile(tileTexturePath);
		tileTextureMap.insert({ tileString.at(tile["name"]), texture });




		std::string decorTexturePath = "Resources/Textures/Decorations/";
		auto jsonDecors = tile["decorations"];
		std::vector < std::string > decors;
		for (std::string decor : jsonDecors) {
			decors.push_back(decor);
			std::string tempPath = decorTexturePath;
			tempPath.append(decor);


			sf::Texture texture;
			texture.loadFromFile(tempPath);

			decorTextureMap.insert({ decorString.at(decor), std::move(texture) });


			context->assets->AddTexture(decor, tempPath);
		}
		context->assets->AddTileDecor(tileString.at(tile["name"]), decors);
		Tile newTile(tile);
		context->assets->AddTile(tileString.at(tile["name"]), newTile);
	}


	sf::RenderTexture tileSetTexture;
	int tileCount = j.size();
	int tileSize = Settings::getTileSize();
	int width = 4;
	tileSetTexture.create(width * tileSize, (tileCount / width + 1) * tileSize);

	for (int i = 0; i < tileTextureMap.size(); i++) {
		TileNames name = static_cast<TileNames>(i);
		sf::Texture tried = tileTextureMap[name];
		sf::Sprite tile;
		tile.setTexture(tried);
		tile.setPosition(sf::Vector2f(i % width * tileSize, i / width * tileSize));
		tileSetTexture.draw(tile);
	}

	tileSetTexture.display();
	std::unique_ptr<sf::Texture> tileSet = std::make_unique<sf::Texture>(tileSetTexture.getTexture());
	context->assets->AddTexture("tileSet", std::move(tileSet));



	sf::RenderTexture decorSetTexture;
	tileCount = decorTextureMap.size();
	tileSize = Settings::getTileSize();
	width = 4;
	decorSetTexture.create(width * tileSize, (tileCount / width + 1) * tileSize);

	for (int i = 0; i < decorTextureMap.size(); i++) {
		DecorTiles name = static_cast<DecorTiles>(i);
		sf::Texture tried = decorTextureMap[name];
		sf::Sprite tile;
		tile.setTexture(tried);
		tile.setPosition(sf::Vector2f(i % width * tileSize, i / width * tileSize));
		decorSetTexture.draw(tile);
	}

	decorSetTexture.display();
	std::unique_ptr<sf::Texture> decorSet = std::make_unique<sf::Texture>(decorSetTexture.getTexture());
	context->assets->AddTexture("decorSet", std::move(decorSet));
	//generateTileset(tileTextureMap, "tileSet", context, 1);
	//generateTileset(decorTextureMap, "decorSet", context, 2);
}
//
//template<typename T1>
//void TileLoader::generateTileset(T1 t1, std::string name, std::shared_ptr<Context>& context, int mode) {
//	sf::RenderTexture tileSetTexture;
//	int tileSize = Settings::getTileSize();
//	int width = 4;
//	tileSetTexture.create(width * tileSize, (t1.size() / width + 1) * tileSize);
//	if (mode == 1) {
//
//		for (int i = 0; i < t1.size(); i++) {
//			TileNames name = static_cast<TileNames>(i);
//			sf::Texture tried = t1.at(name);
//			sf::Sprite tile;
//			tile.setTexture(tried);
//			tile.setPosition(sf::Vector2f(i % width * tileSize, i / width * tileSize));
//			tileSetTexture.draw(tile);
//		}
//	}
//	else if (mode == 2) {
//		for (int i = 0; i < t1.size(); i++) {
//			DecorTiles name = static_cast<DecorTiles>(i);
//			sf::Texture tried = t1.at(name);
//			sf::Sprite tile;
//			tile.setTexture(tried);
//			tile.setPosition(sf::Vector2f(i % width * tileSize, i / width * tileSize));
//			tileSetTexture.draw(tile);
//		}
//	}
//
//
//
//	tileSetTexture.display();
//	std::unique_ptr<sf::Texture> tileSet = std::make_unique<sf::Texture>(tileSetTexture.getTexture());
//	context->assets->AddTexture(name, std::move(tileSet));
//}
