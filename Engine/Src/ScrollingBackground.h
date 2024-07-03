#pragma once
#include <iostream>
#include "GameObjectFactory.h"
#include "PlatformerObject.h"

class ScrollingBackground : public PlatformerObject
{
public:
    
    virtual ~ScrollingBackground() {}
    ScrollingBackground();
    
    virtual void draw();
    virtual void update();
    virtual void clean();
    
    virtual void load(std::unique_ptr<LoaderParams> const &pParams);
    
private:
    
    int m_scrollSpeed;
    
    int count;
    int maxcount;
    
    SDL_Rect m_srcRect1;
    SDL_Rect m_srcRect2;
    
    SDL_Rect m_destRect1;
    SDL_Rect m_destRect2;
    
    int m_srcRect1Width;
    int m_srcRect2Width;
    
    int m_destRect1Width;
    int m_destRect2Width;
};

class ScrollingBackgroundCreator : public BaseCreator
{
public:
    
    virtual GameObject* createGameObject() const
    {
        return new ScrollingBackground();
    }
};

//This ScrollingBackground class uses two destination rectangles and two source rectangles; one expands while the other contracts.Once the expanding rectangle has reached its full width, both rectangles are resetand the loop continues.
