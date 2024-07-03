#pragma once
#include "GameState.h"


// This is an abstract base class which extends from GameState .The class will declare a function that sets the callbacks for any items that need it and it will alsohave a vector of the Callback objects as a member; this will be used within thesetCallbacks function for each state.

class MenuState : public GameState
{
public:
    
    virtual ~MenuState() {}
    
protected:
    
    typedef void(*Callback)();
    virtual void setCallbacks(const std::vector<Callback>& callbacks) = 0;
    
    std::vector<Callback> m_callbacks;
};
