#pragma once
#include <string>
#include <vector>

// Abstract base class, it does not have any functionality.
class GameState
{
public:
    
    virtual ~GameState() {}
    
    virtual void update() = 0;
    virtual void render() = 0;
    
    // calling as soon as the state is loaded.
    virtual bool onEnter() = 0;
    // as soon as the state is closed.
    virtual bool onExit() = 0;
    
    virtual void resume() {}
    
    //each state will need to define this function and return its own staticconst ID.
    virtual std::string getStateID() const = 0;
    
protected:
    
    GameState() : m_loadingComplete(false), m_exiting(false)
    {
        
    }
    
    bool m_loadingComplete;
    bool m_exiting;
    
    // to clear all the textures that are loaded for the state.
    std::vector<std::string> m_textureIDList;
};
