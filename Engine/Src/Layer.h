#pragma once

class Level;

// Abstract base class. all the layer types will derive from this class. 
class Layer
{
public:

    virtual ~Layer() {}
    
    virtual void render() = 0;
    virtual void update(Level* pLevel) = 0;
};
