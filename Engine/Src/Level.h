#pragma once
#include <iostream>
#include <vector>
#include "Layer.h"
#include "LevelParser.h"
#include "Player.h"
#include "CollisionManager.h"

class TileLayer;

struct Tileset
{
    int firstGridID;
    int tileWidth;
    int tileHeight;
    //int spacing;
    //int margin;
    int width;
    int height;
    int numColumns;
    std::string name;
};

class Level
{
public:
    
    ~Level();
    
    void update();
    void render();
    
    // we can pass this into the parser in order to load the map.
    std::vector<Tileset>* getTilesets() { return &m_tilesets; }

    // getter function to get the layers.
    std::vector<Layer*>* getLayers() { return &m_layers; }    
    std::vector<TileLayer*>* getCollisionLayers() { return &m_collisionLayers; }
    
    const std::vector<TileLayer*>& getCollidableLayers() { return m_collisionLayers; }
    
    // getter and setters.
    Player* getPlayer() { return m_pPlayer; }
    void setPlayer(Player* pPlayer) { m_pPlayer = pPlayer; }
    
private:
    
    // in order to access the private constructor of level.
    friend class LevelParser;
    
    Level();
    
    Player* m_pPlayer;    // pointer to player.
    
    //we will store a vector of the Layer* objects in the level class.
    std::vector<Layer*> m_layers;
    // vector of tileset objects.
    std::vector<Tileset> m_tilesets;
    std::vector<TileLayer*> m_collisionLayers;
};
