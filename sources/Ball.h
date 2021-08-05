#pragma once
#pragma once
#include <cocos2d.h>

#define BALL_MOVEMENT_SPEED 4

class Ball {
public:

	Ball(cocos2d::Layer* layer);

	void MoveBall();

	void changeXdir();

	void changeYdir();

	float getX(); 

	float getY();

	float getWidth();

	float getHeight();

	void remove();

private:
	cocos2d::RefPtr<cocos2d::Sprite> _spriteBall;

	cocos2d::Size visibleSize;

	float x;
	float y;

	float speed_x;
	float speed_y;

	float width;
	float height;

	cocos2d::Layer* layer;
};