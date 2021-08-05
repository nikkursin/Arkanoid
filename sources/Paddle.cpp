#include "Paddle.h"

Paddle::Paddle(cocos2d::Layer* layer) {
	this->layer = layer;
	_spritePaddle = cocos2d::Sprite::create("textures/paddle.png");
	cocos2d::Vec2 viewCenter = layer->getPosition() + layer->getContentSize() / 2.0f;
	_spritePaddle->setPosition(viewCenter.x, viewCenter.y - 280);
	auto mouseListener = cocos2d::EventListenerMouse::create();

	mouseListener->onMouseMove = CC_CALLBACK_1(Paddle::onMouseMove, this);
	
	layer->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, layer);

	this->width = _spritePaddle ->getBoundingBox().size.width;
	this->height = _spritePaddle ->getBoundingBox().size.height;

	layer->addChild(_spritePaddle);
}

void Paddle::onMouseMove(cocos2d::EventMouse* event) {
	cocos2d::Vec2 viewCenter = layer->getPosition() + layer->getContentSize() / 2.0f;
	_spritePaddle->setPosition(event->getCursorX(), viewCenter.y - 280);
}

float Paddle::getY() {
	return _spritePaddle->getPositionY();
}

float Paddle::getX() {
	return _spritePaddle->getPositionX();
}

float Paddle::getWidth() {
	return width;
}

float Paddle::getHeight() {
	return height;
}

void Paddle::remove() {
	layer->removeChild(_spritePaddle);
}