#pragma once
#include <string>

struct MapData
{
	int version = 0;
	std::string tilesheet = "";
	std::string mapName = "";
	int mapPositionX = 0;
	int	mapPositionY = 0;
	int	cellSizeX = 0;
	int	cellSizeY = 0;
	int	totalCellsX = 0;
	int	totalCellsY = 0;
	int	mapScaleX = 0;
	int mapScaleY = 0;
	int	dataLength = 0;
	int* data = nullptr;
};

