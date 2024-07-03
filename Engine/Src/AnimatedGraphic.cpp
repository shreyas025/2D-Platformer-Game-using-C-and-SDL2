#include "AnimatedGraphic.h"
using namespace std;

AnimatedGraphic::AnimatedGraphic() : PlatformerObject()
{
    m_animSpeed = 0;  // initializing our member variables.
    m_frameCount = 0;
}

void AnimatedGraphic::load(std::unique_ptr<LoaderParams> const &pParams)
{
    PlatformerObject::load(pParams);
    m_animSpeed = pParams->getAnimSpeed();
}

void AnimatedGraphic::draw()
{
    PlatformerObject::draw();
}

void AnimatedGraphic::update()
{
    m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) % m_numFrames));
}

void AnimatedGraphic::clean()
{
    PlatformerObject::clean();
}