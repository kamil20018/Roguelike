#include "ActorManager.h"

ActorManager::ActorManager(std::shared_ptr<Context> context, std::shared_ptr<World> world) : enemyGenerator(context, world) {
	this->context = context;
	updateLoadedChunks();
}

ActorManager::ActorManager(std::shared_ptr<Context> context, std::shared_ptr<World> world, json saveData) : enemyGenerator(context, world) {
	this->context = context;


	json cenChunk = saveData["centerChunk"];
	this->centreChunk = sf::Vector2i(cenChunk[0], cenChunk[1]);

	auto loadedChunks = enemyGenerator.loadChunkFromJson(saveData["enemyChunks"]);
	for (auto& chunk : loadedChunks) {
		chunks.insert({ chunk.getPosition(), std::move(chunk) });
	}

	updateLoadedChunks();
}

void ActorManager::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (sf::Vector2i chunkPos : loadedChunks) {
		target.draw(chunks.at(chunkPos), states);
	}
}
void ActorManager::takeTurn() {
	for (auto pos : loadedChunks) {
		chunks.at(pos).takeTurn();
	}
	for (auto pos : loadedChunks) {
		auto enemies = chunks.at(pos).getOutOfBoundsEnemies();
		for (auto& enemy : enemies) {
			//std::cout << "pos in manager: " << enemy->getPosition().x << " " << enemy->getPosition().y << std::endl;
			chunks.at(globalPosToChunk(enemy->getPosition())).addEnemy(std::move(enemy));
		}
	}
}

json ActorManager::serialize() {
	json actorManager;

	for (auto& it : chunks) {
		actorManager["enemyChunks"].push_back(it.second.serialize());
	}

	actorManager["centerChunk"] = { centreChunk.x, centreChunk.y };

	return actorManager;
}

void ActorManager::updateEnemiesChunkPos() {
}

void ActorManager::updateLoadedChunks() {
	loadedChunks.clear();
	std::vector<sf::Vector2i> vectors = utils::unitVectors;
	vectors.push_back(sf::Vector2i());

	for (sf::Vector2i pos : vectors) {
		sf::Vector2i chunkPos = pos + centreChunk;
		loadedChunks.insert(chunkPos);
		if (chunks.find(chunkPos) == chunks.end()) {
			chunks.insert({ chunkPos, enemyGenerator.generateChunk(chunkPos) });
		}
	}
}


