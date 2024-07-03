#pragma once
#include <string>
#include <map>
#include <iostream>
#include "GameObject.h"

class BaseCreator
{
public:
    
    virtual GameObject* createGameObject() const = 0;
    virtual ~BaseCreator() {}
};

class GameObjectFactory
{
public:
    
    static GameObjectFactory* Instance()
    {
        if(pInstance == 0)
        {
            pInstance = new GameObjectFactory();
        }
        
        return pInstance;
    }
    
    bool registerType(std::string typeID, BaseCreator* pCreator)
    {
        // find the type
        std::map<std::string, BaseCreator*>::iterator it = m_creators.find(typeID);
        
        // if the type is already registered, function deletes the parameter.
        if(it != m_creators.end())
        {
            delete pCreator;
        }
        
        // if the type is not already registered, assigned to the map.
        m_creators[typeID] = pCreator;
        
        return true;
    }
    
    // creates the objects.
    GameObject* create(std::string typeID)
    {
        std::map<std::string, BaseCreator*>::iterator it = m_creators.find(typeID);
        
        if(it == m_creators.end())
        {
            std::cout << "could not find type: " << typeID << "\n";
            return NULL;
        }
    
        // creator returns a new instance of the object as the pointer to the Gameobject. 
        BaseCreator* pCreator = (*it).second;
        return pCreator->createGameObject();
    }
    
private:
    
    GameObjectFactory() {}
    ~GameObjectFactory() {}
    

    //This map holds the important elements of our factory, the functions of the class essentially add 
    // or remove from the map.
    std::map<std::string, BaseCreator*> m_creators;
    
    static GameObjectFactory* pInstance;
};

typedef GameObjectFactory TheGameObjectFactory;
