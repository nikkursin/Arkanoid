#pragma once
#include <cocos2d.h>

class Paddle {
public:
	Paddle (cocos2d::Layer* layer);

	void onMouseMove(cocos2d::EventMouse* event);

	float getX();

	float getY();

	float getWidth();

	float getHeight();

	void remove();

private:
	cocos2d::RefPtr<cocos2d::Sprite> _spritePaddle;

	float width;
	float height;

	cocos2d::Layer* layer;
};