#pragma once
#include <cocos2d.h>

#include "Paddle.h"
#include "Block.h"
#include "Ball.h"

class ArkanoidLayer : public cocos2d::Layer
{
public:
    using Super = cocos2d::Layer;

    static cocos2d::RefPtr<cocos2d::Scene> createScene();

    virtual bool init() override;

    void CheckCollision(float dt);

    void Collision(Ball* ball, Block* block);

    void Collision(Ball* ball, Paddle* paddle);

    void MoveBall(float dt); 

    void WinCheck(float dt);
    void LoseCheck(float dt);

   CREATE_FUNC(ArkanoidLayer);

private:

    Paddle* paddle; 
    
    Ball* ball ;

    Block* block;

};
