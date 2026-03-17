#pragma once
#include <string>
#include <vector> // Required for layer storage

struct MapData
{
private:
    std::string m_tilesheet = "";
    std::string m_name = "";

    int m_mapPositionX = 0;
    int m_mapPositionY = 0;

    int m_cellSizeX = 0;
    int m_cellSizeY = 0;

    int m_totalCellsX = 0;
    int m_totalCellsY = 0;

    int m_mapScaleX = 0;
    int m_mapScaleY = 0;

    // Updated: Support for multiple layers
    int m_numLayers = 0;
    int m_dataLength = 0; // The length of a single layer (Width * Height)

    // Points to the nested vector of IDs in the Map class
    const std::vector<std::vector<int>>* m_layerData = nullptr;

public:
    MapData(const std::string& tilesheet, const std::string& name,
        int mapPositionX, int mapPositionY, int cellSizeX, int cellSizeY,
        int totalCellsX, int totalCellsY, int mapScaleX, int mapScaleY,
        int numLayers, int dataLength, const std::vector<std::vector<int>>* layerData)
    {
        m_tilesheet = tilesheet;
        m_name = name;

        m_mapPositionX = mapPositionX;
        m_mapPositionY = mapPositionY;

        m_cellSizeX = cellSizeX;
        m_cellSizeY = cellSizeY;

        m_totalCellsX = totalCellsX;
        m_totalCellsY = totalCellsY;

        m_mapScaleX = mapScaleX;
        m_mapScaleY = mapScaleY;

        // New fields
        m_numLayers = numLayers;
        m_dataLength = dataLength;
        m_layerData = layerData;
    }

    inline const std::string& GetTilesheet() const { return m_tilesheet; }
    inline const std::string& GetName() const { return m_name; }

    inline const int& GetMapPositionX() const { return m_mapPositionX; }
    inline const int& GetMapPositionY() const { return m_mapPositionY; }

    inline const int& GetCellSizeX() const { return m_cellSizeX; }
    inline const int& GetCellSizeY() const { return m_cellSizeY; }

    inline const int& GetTotalCellsX() const { return m_totalCellsX; }
    inline const int& GetTotalCellsY() const { return m_totalCellsY; }

    inline const int& GetMapScaleX() const { return m_mapScaleX; }
    inline const int& GetMapScaleY() const { return m_mapScaleY; }

    // Layer Getters
    inline int GetNumLayers() const { return m_numLayers; }
    inline int GetDataLength() const { return m_dataLength; }

    // Helper to get a specific layer's vector of IDs
    inline const std::vector<int>& GetLayerData(int layerIndex) const {
        return (*m_layerData)[layerIndex];
    }
};