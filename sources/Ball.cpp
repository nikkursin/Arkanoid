#include "Ball.h"

Ball::Ball(cocos2d::Layer* layer) {
	this->layer = layer;
	visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	this->x = visibleSize.width / 2; 
	this->y = visibleSize.height / 2;
	visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

	_spriteBall = cocos2d::Sprite::create("textures/Ball.png");

	_spriteBall->setPosition(x, y);

	this->speed_x = -BALL_MOVEMENT_SPEED;
	this->speed_y = -BALL_MOVEMENT_SPEED;

	this->width = _spriteBall->getBoundingBox().size.width;
	this->height = _spriteBall->getBoundingBox().size.height;

	layer->addChild(_spriteBall, 100);
}

void Ball::MoveBall() {

	if (x <= 0 + _spriteBall->getContentSize().width / 2 || x >= visibleSize.width - _spriteBall->getContentSize().width / 2) {
		this->changeXdir();
	}
	if ( y >= visibleSize.height - _spriteBall->getContentSize().height / 2) {
		this->changeYdir();
	}

	this->x += speed_x; 
	this->y += speed_y;

	_spriteBall->setPosition(x, y); 
}

void Ball::changeXdir() {
	speed_x = -(speed_x);
}

void Ball::changeYdir() {
	speed_y = -(speed_y);
}

float Ball::getX() {
	return x;
}

float Ball::getY() {
	return y;
}

float Ball::getWidth() {
	return width;
}

float Ball::getHeight() {
	return height;
}

void Ball::remove() {
	layer->removeChild(_spriteBall);
}