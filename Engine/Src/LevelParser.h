#pragma once
#include <iostream>
#include <vector>
#include "tinyxml.h"

class Level;
struct Tileset;
class Layer;
class TileLayer;

class LevelParser
{
public:
    // call whenever we want to create a level.
    Level* parseLevel(const char* stateFile);
    
private:
    
    void parseTextures(TiXmlElement* pTextureRoot);
    void parseTilesets(TiXmlElement* pTilesetRoot, std::vector<Tileset>* pTilesets);
    void parseObjectLayer(TiXmlElement* pObjectElement, std::vector<Layer*> *pLayers, Level* pLevel);
    void parseTileLayer(TiXmlElement* pTileElement, std::vector<Layer*> *pLayers, const std::vector<Tileset>* pTilesets, std::vector<TileLayer*> *pCollisionLayers);
    
    int m_tileSize;
    int m_width;
    int m_height;
};


//To ensure that this function must be used to create a Level object, we will make the
//Level class' constructor private and make it a friend class of LevelParser: