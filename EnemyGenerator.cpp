#include "EnemyGenerator.h"

EnemyGenerator::EnemyGenerator(std::shared_ptr<Context> context, std::shared_ptr<World> world) {
	this->world = world;
	this->context = context;
}

EnemyChunk EnemyGenerator::generateChunk(sf::Vector2i chunkPos) {
	EnemyChunk chunk(chunkPos);
	sf::Vector2i offset(chunkPos.x * Settings::getChunkSize().x, chunkPos.y * Settings::getChunkSize().y);
	std::unique_ptr<Enemy> enemy1 = std::make_unique<Enemy>(_assets->GetTexture("goblin"), offset + sf::Vector2i(5, 5), world);
	std::unique_ptr<Enemy> enemy2 = std::make_unique<Enemy>(_assets->GetTexture("goblin"), offset + sf::Vector2i(6, 6), world);
	std::unique_ptr<Enemy> enemy3 = std::make_unique<Enemy>(_assets->GetTexture("goblin"), offset + sf::Vector2i(4, 4), world);
	chunk.addEnemy(std::move(enemy1));
	chunk.addEnemy(std::move(enemy2));
	chunk.addEnemy(std::move(enemy3));
	return chunk;
}

std::vector<EnemyChunk> EnemyGenerator::loadChunkFromJson(json saveData) {
	std::vector<EnemyChunk> generatedChunks;


	for (json enemyChunk : saveData) {
		json position = enemyChunk["position"];
		EnemyChunk chunk(sf::Vector2i(position[0], position[1]));

		for (auto enemy : enemyChunk["enemies"]) {
			json pos = enemy["position"];
			chunk.addEnemy(std::move(std::make_unique<Enemy>(_assets->GetTexture("goblin"), sf::Vector2i(pos[0], pos[1]), world)));
		}
		generatedChunks.push_back(std::move(chunk));
	}


	return generatedChunks;
}
