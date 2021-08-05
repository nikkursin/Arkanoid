#include "ArkanoidLayer.h"
#include "audio/include/AudioEngine.h"
#include "cocos2d.h"

cocos2d::RefPtr<cocos2d::Scene> ArkanoidLayer::createScene()
{
    auto scene = cocos2d::Scene::create();
    auto layer = ArkanoidLayer::create();
    assert(scene && layer && "Something went wrong: could not create scene");
    scene->addChild(layer);
    return scene;
}

bool ArkanoidLayer::init()
{
    if (!Super::init())
        return false;
    
    block = new Block(this); 

    paddle = new Paddle(this);

    ball = new Ball(this);

    this->schedule(CC_SCHEDULE_SELECTOR(ArkanoidLayer::MoveBall), 1.0f / 60);

    this->schedule(CC_SCHEDULE_SELECTOR(ArkanoidLayer::CheckCollision), 1.0f / 60);

    this->schedule(CC_SCHEDULE_SELECTOR(ArkanoidLayer::WinCheck), 1.0f / 60);
    
    this->schedule(CC_SCHEDULE_SELECTOR(ArkanoidLayer::LoseCheck), 1.0f / 60);

    return true;
}



void ArkanoidLayer::MoveBall(float dt) {
    ball->MoveBall();
}


void ArkanoidLayer::CheckCollision(float dt) {
    Collision(ball, paddle); 
    Collision(ball, block); 
}

    
void ArkanoidLayer::Collision(Ball* ball, Block* block) {
    for (int i = 0; i < block->GetVec().size(); i++) {
        if ((((block->getY(i) + block->getHeight(i) / 2 >= ball->getY() - ball->getHeight() / 2) &&   // Checking intersection with Y
            (ball->getY() - ball->getHeight() / 2 >= block->getY(i) - block->getHeight(i) / 2)) ||
            ((block->getY(i) - block->getHeight(i) / 2 <= ball->getY() + ball->getHeight() / 2) &&
                (ball->getY() + ball->getHeight() / 2 <= block->getY(i) + block->getHeight(i) / 2))) &&
            (((block->getX(i) + block->getWidth(i) / 2 >= ball->getX() - ball->getWidth() / 2) &&   // Checking intersection with X
                (ball->getX() - ball->getWidth() / 2 >= block->getX(i) - block->getWidth(i) / 2)) ||
                ((block->getX(i) - block->getWidth(i) / 2 <= ball->getX() + ball->getWidth() / 2) &&
                    (ball->getX() + ball->getWidth() / 2 <= block->getX(i) + block->getWidth(i) / 2)))
            ) {
            ball->changeYdir();
            block->remove(i);
            cocos2d::AudioEngine::play2d("sounds/hit.ogg");
        }
    }
}

void ArkanoidLayer::Collision(Ball* ball, Paddle* paddle) {
    if ((((paddle->getY() + paddle->getHeight() / 2 >= ball->getY() - ball->getHeight() / 2) &&   // Checking intersection with Y
        (ball->getY() - ball->getHeight() / 2 >= paddle->getY() - paddle->getHeight() / 2)) ||
        ((paddle->getY() - paddle->getHeight() / 2 <= ball->getY() + ball->getHeight() / 2) &&
            (ball->getY() + ball->getHeight() / 2 <= paddle->getY() + paddle->getHeight() / 2))) &&
        (((paddle->getX() + paddle->getWidth() / 2 >= ball->getX() - ball->getWidth() / 2) &&   // Checking intersection with X
            (ball->getX() - ball->getWidth() / 2 >= paddle->getX() - paddle->getWidth() / 2)) ||
            ((paddle->getX() - paddle->getWidth() / 2 <= ball->getX() + ball->getWidth() / 2) &&
                (ball->getX() + ball->getWidth() / 2 <= paddle->getX() + paddle->getWidth() / 2)))
        ) {
        ball->changeYdir();
    }
       
}

void ArkanoidLayer::WinCheck(float dt) {
    if (block->GetVec().size() == 0) {
        cocos2d::ccMessageBox("You WIN!", "WINNER");
        block->remove();
        ball->remove();
        paddle->remove();
        ArkanoidLayer::init();
    }

}

void ArkanoidLayer::LoseCheck(float dt) {
    if (ball->getY() <= 0 + ball->getHeight() / 2) {
        cocos2d::ccMessageBox("You LOSE(((", "LOSER");
        block->remove();
        ball->remove();
        paddle->remove();
        ArkanoidLayer::init();
    }

}