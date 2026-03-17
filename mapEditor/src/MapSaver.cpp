#include "MapSaver.h"
#include <fstream>
#include <iostream>

#define MAP_VERSION_NUMBER 1

MapSaver::MapSaver(const Grid& grid) : m_grid(grid) {}

MapSaver::~MapSaver() {}

void MapSaver::Save(const std::string& fileName, const MapData& mapData, const Map& map) {
    std::ofstream file(fileName);

    if (!file) {
        std::cout << "Failed to create file: " << fileName << std::endl;
        return;
    }

    file << "[Map]" << std::endl;
    file << "version=" << MAP_VERSION_NUMBER << std::endl;
    file << "layers=" << mapData.GetNumLayers() << std::endl; // Save how many layers exist
    file << "tilesheet=" << mapData.GetTilesheet() << std::endl;
    file << "mapName =" << mapData.GetName() << std::endl;
    file << "mapPositionX =" << mapData.GetMapPositionX() << std::endl;
    file << "mapPositionY =" << mapData.GetMapPositionY() << std::endl;
    file << "cellSizeX =" << mapData.GetCellSizeX() << std::endl;
    file << "cellSizeY =" << mapData.GetCellSizeY() << std::endl;
    file << "totalCellsX =" << mapData.GetTotalCellsX() << std::endl;
    file << "totalCellsY =" << mapData.GetTotalCellsY() << std::endl;
    file << "mapScaleX =" << mapData.GetMapScaleX() << std::endl;
    file << "mapScaleY =" << mapData.GetMapScaleY() << std::endl;
    file << "dataLength =" << mapData.GetDataLength() << std::endl;
    // Save each layer's data on its own line
    for (int l = 0; l < mapData.GetNumLayers(); l++) {
        file << "layer_" << l << "_data=";
        const std::vector<int>& currentLayer = mapData.GetLayerData(l);

        for (size_t i = 0; i < currentLayer.size(); i++) {
            file << currentLayer[i] << (i == currentLayer.size() - 1 ? "" : ",");
        }
        file << std::endl;
    }

    file.close();
};