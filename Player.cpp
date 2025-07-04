#include "Player.h"
#include "Actor.h"


Player::Player() {
	name_ = "";
	posX_ = 0;
	posY_ = 0;
}

Player::Player(std::string name, float posX, float posY) {
	setName(name);
	setPos(posX, posY);
}

void Player::setName(const std::string& name) {
	name_ = name;
}

std::string Player::getName() const {
	return name_;
}

void Player::setPos(const float& posX, const float& posY) {
	posX_ = posX;
	posY_ = posY;
	
}



