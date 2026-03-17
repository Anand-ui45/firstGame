#include "Map.h"
#include <iostream>

Map::Map(const Grid& grid, const MouseTile& mouseTile)
    : m_grid(grid), m_mouseTile(mouseTile)
{
    int totalCells = m_grid.GetTotalCells().x * m_grid.GetTotalCells().y;

    m_layerIDs.resize(m_numLayers, std::vector<int>(totalCells, -1));

    // Fix: SFML 3.0 uses Triangles (6 vertices per tile) instead of Quads
    m_layerVertices.resize(m_numLayers, sf::VertexArray(sf::PrimitiveType::Triangles, totalCells * 6));
}

Map::~Map() {}

void Map::Initialize() {
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

        if (i >= 0 && i < m_layerIDs[m_activeLayer].size()) {
            if (m_layerIDs[m_activeLayer][i] != m_mouseTile.GetCurrentTileID()) {

                m_layerIDs[m_activeLayer][i] = m_mouseTile.GetCurrentTileID();
                sf::IntRect textureRect = m_mouseTile.GetTileSprite().getTextureRect();

                // Fix for image_3e5bc8.png: SFML 3.0 Rect member names
                float texL = (float)textureRect.position.x;
                float texT = (float)textureRect.position.y;
                float texW = (float)textureRect.size.x;
                float texH = (float)textureRect.size.y;

                float scaleX = m_grid.GetScale().x;
                float scaleY = m_grid.GetScale().y;
                float cellSizeX = m_grid.GetCellSize().x * scaleX;
                float cellSizeY = m_grid.GetCellSize().y * scaleY;

                // 6 vertices for 2 triangles (making one square)
                sf::Vertex* tri = &m_layerVertices[m_activeLayer][i * 6];

                // Triangle 1
                tri[0].position = sf::Vector2f(tilePosition.x, tilePosition.y);
                tri[1].position = sf::Vector2f(tilePosition.x + cellSizeX, tilePosition.y);
                tri[2].position = sf::Vector2f(tilePosition.x, tilePosition.y + cellSizeY);
                // Triangle 2
                tri[3].position = sf::Vector2f(tilePosition.x + cellSizeX, tilePosition.y);
                tri[4].position = sf::Vector2f(tilePosition.x + cellSizeX, tilePosition.y + cellSizeY);
                tri[5].position = sf::Vector2f(tilePosition.x, tilePosition.y + cellSizeY);

             
                tri[0].texCoords = sf::Vector2f(texL, texT);
                tri[1].texCoords = sf::Vector2f(texL + texW, texT);
                tri[2].texCoords = sf::Vector2f(texL, texT + texH);

                tri[3].texCoords = sf::Vector2f(texL + texW, texT);
                tri[4].texCoords = sf::Vector2f(texL + texW, texT + texH);
                tri[5].texCoords = sf::Vector2f(texL, texT + texH);

               
                sf::Color color = (m_layerIDs[m_activeLayer][i] == -1) ? sf::Color::Transparent : sf::Color::White;
                for (int v = 0; v < 6; v++) tri[v].color = color;
            }
        }
    }
}

void Map::Draw(sf::RenderWindow& window) {
    sf::RenderStates states(&m_tileTexture); 
    for (int l = 0; l < m_numLayers; l++) {
        window.draw(m_layerVertices[l], states);
    }
}