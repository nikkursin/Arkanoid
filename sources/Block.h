#pragma once
#include <cocos2d.h>


struct Props {
	float x; 
	float y;
	float width;
	float height; 
};

class Block {
private:
	std::vector <std::pair<Props, cocos2d::RefPtr<cocos2d::Sprite>>> Blocks;

	cocos2d::Layer* layer; 

public:
	Block(cocos2d::Layer* layer);

	float getX(int i);

	float getY(int i);

	float getWidth(int i);

	float getHeight(int i);

	void remove(int i);

	void remove();

	std::vector <std::pair<Props, cocos2d::RefPtr<cocos2d::Sprite>>> GetVec();

};