#pragma once
#include <string>
#include <core/MapData.h>
#include "grid.h"
#include "Map.h"

class MapSaver{
private:
	const Grid& m_grid;

	


public:
	MapSaver(const Grid& grid);

	~MapSaver();
	void Save(const std::string& fileName,const MapData& mapData, const Map& map);
};

