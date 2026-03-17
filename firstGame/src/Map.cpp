#include "Map.h"
#include <iostream>

Map::Map(const Grid& grid, const MouseTile& mouseTile)
    : m_grid(grid), m_mouseTile(mouseTile)
{
    int totalCells = m_grid.GetTotalCells().x * m_grid.GetTotalCells().y;

    // Initialize the layers
    m_layerIDs.resize(m_numLayers, std::vector<int>(totalCells, -1)); // -1 means empty
    m_layerSprites.resize(m_numLayers, std::vector<sf::Sprite>(totalCells));
}

Map::~Map() {
    // std::vector handles its own memory, no more 'delete[]' needed!
}

void Map::Initialize() {
    // Ensure the texture is loaded for the sprites to use
    if (!m_tileTexture.loadFromFile("assets/world/prison/tilesheet.png")) {
        std::cout << "Map Texture failed to load!" << std::endl;
    }
}

void Map::Load() {}

void Map::Update(float deltatime) {
    sf::Vector2f tilePosition;
    sf::Vector2i gridPosition;

    if (m_mouseTile.isMouseClickedOnTile(tilePosition, gridPosition)) {
        int i = gridPosition.x + gridPosition.y * m_grid.GetTotalCells().x;

        // Safety check for vector bounds
        if (i >= 0 && i < m_layerIDs[m_activeLayer].size()) {
            // Update only the active layer
            m_layerIDs[m_activeLayer][i] = m_mouseTile.GetCurrentTileID();
            m_layerSprites[m_activeLayer][i] = m_mouseTile.GetTileSprite();
            m_layerSprites[m_activeLayer][i].setPosition(tilePosition);
        }
    }
}

void Map::Draw(sf::RenderWindow& window) {
    // Loop through layers from bottom (0) to top (m_numLayers)
    for (int l = 0; l < m_numLayers; l++) {
        for (int i = 0; i < m_layerIDs[l].size(); i++) {
            // Only draw if the tile ID is not -1 (not empty)
            if (m_layerIDs[l][i] != -1) {
                window.draw(m_layerSprites[l][i]);
            }
        }
    }
}