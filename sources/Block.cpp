#pragma once
#include "Block.h"

Block::Block(cocos2d::Layer* layer) {
	this->layer = layer; 
	int lev_arr[6][8] = {
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
	};
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			if (lev_arr[i][j] == 1) {
				std::pair < Props, cocos2d::RefPtr<cocos2d::Sprite >> temp; 
				temp.second = cocos2d::Sprite::create("textures/block.png");
				temp.second->setPosition(22 + ((j)* (temp.second->getBoundingBox().size.width + 4) + 4 + temp.second->getBoundingBox().size.width / 2),
					abs(i - 6) * 55 + layer->getBoundingBox().size.height / 2);
				layer->addChild(temp.second);
				temp.first.x = temp.second->getPositionX();
				temp.first.y = temp.second->getPositionY();
				temp.first.height = temp.second->getBoundingBox().size.height;
				temp.first.width = temp.second->getBoundingBox().size.width;
				Blocks.push_back(temp); 
			}
		}
	}
}

float Block::getX(int i) {
	return Blocks[i].first.x;
}

float Block::getY(int i) {
	return Blocks[i].first.y;
}

float Block::getWidth(int i) {
	return Blocks[i].first.width;
}

float Block::getHeight(int i) {
	return Blocks[i].first.height;
}

void Block::remove(int i) {
	layer->removeChild(Blocks[i].second);
	Blocks.erase(Blocks.begin() + i); 
}

void Block::remove() {
	layer->removeAllChildren();
}

std::vector <std::pair<Props, cocos2d::RefPtr<cocos2d::Sprite>>> Block::GetVec() {
	return Blocks;
}