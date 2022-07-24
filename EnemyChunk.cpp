#include "EnemyChunk.h"

EnemyChunk::EnemyChunk(sf::Vector2i pos) {
	this->position = pos;
	this->size = Settings::getChunkSize();
}

void EnemyChunk::addEnemy(std::unique_ptr<Enemy> enemy) {
	enemies.push_back(std::move(enemy));
}

void EnemyChunk::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (auto const& enemy : enemies) {
		target.draw(*enemy);
	}
}

void EnemyChunk::takeTurn() {
	for (auto& enemy : enemies) {
		enemy->takeTurn();
		//if (!inBounds(enemy->getPosition())) {
		//	std::cout << "not in bounds: " << enemy->getPosition().x << " " << enemy->getPosition().y << std::endl;
		//}
	}
	//getOutOfBoundsEnemies();
}

bool EnemyChunk::isTraversable(sf::Vector2i pos) {
	for (auto& enemy : enemies) {
		if (enemy->getPosition() == pos) {
			return false;
		}
	}
	return true;
}

std::vector<std::unique_ptr<Enemy>> EnemyChunk::getOutOfBoundsEnemies() {
	std::vector<int> enemyIndices;
	std::vector<std::unique_ptr<Enemy>> enemiesOutOfBounds;
	for (int i = enemies.size() - 1; i >= 0; i--) {
		if (!inBounds(enemies[i]->getPosition())) {
			enemyIndices.push_back(i);
		}
	}
	for (int index : enemyIndices) {
		enemiesOutOfBounds.push_back(std::move(enemies[index]));
		enemies.erase(enemies.begin() + index);
	}

	return enemiesOutOfBounds;
}

json EnemyChunk::serialize() {
	json enemyChunk;

	enemyChunk["position"] = { position.x, position.y };

	for (auto& enemy : enemies) {
		enemyChunk["enemies"].push_back(enemy->serialize());
	}
	return enemyChunk;
}

sf::Vector2i EnemyChunk::getPosition() {
	return this->position;
}

bool EnemyChunk::inBounds(sf::Vector2i pos) {
	int shiftX = position.x * size.x;
	int shiftY = position.y * size.y;
	int xLeft = shiftX;
	int xRight = shiftX + size.x - 1;

	int yTop = shiftY + size.y - 1;
	int yBottom = shiftY;

	return pos.x >= xLeft and pos.x <= xRight and pos.y >= yBottom and pos.y <= yTop;
}
