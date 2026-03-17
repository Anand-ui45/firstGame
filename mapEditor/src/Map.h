#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Grid.h"
#include "MouseTile.h"

class Map {
private:
    const Grid& m_grid;
    const MouseTile& m_mouseTile;
    sf::Texture m_tileTexture;

    int m_numLayers = 3;
    int m_activeLayer = 0;

    // Keep the IDs for saving/loading
    std::vector<std::vector<int>> m_layerIDs;

    // NEW: Replace m_layerSprites with an array of vertices for each layer
    std::vector<sf::VertexArray> m_layerVertices;

public:
    Map(const Grid& grid, const MouseTile& mouseTile);
    ~Map();

    void Initialize();
    void Load();
    void Update(float deltatime);
    void Draw(sf::RenderWindow& window);

    void SetActiveLayer(int layer) { if (layer >= 0 && layer < m_numLayers) m_activeLayer = layer; }
    int GetActiveLayer() const { return m_activeLayer; }
    int GetNumLayers() const { return m_numLayers; }

    const std::vector<std::vector<int>>& GetAllLayerIDs() const { return m_layerIDs; }
    const std::vector<int>& GetLayerIDs(int layer) const { return m_layerIDs[layer]; }
};