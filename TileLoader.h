#pragma once
#include "Tile.h"
#include "Game.h"
#include "json.hpp"
#include <fstream>
using json = nlohmann::json;

struct Context;

class TileLoader {
public:
	static void loadTilesToContext(std::shared_ptr<Context>& context);
	//template <typename T1>
	//static void generateTileset(T1 t1, std::string name, std::shared_ptr<Context>& context, int mode);

};


