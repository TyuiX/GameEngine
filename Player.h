#pragma once
#include <iostream>

class Player {
public:

	Player();

	Player(std::string name, float posX, float posY);

	void setName(const std::string & name);

	std::string getName() const;

	void setPos(const float& posX, const float& posY);

	



private:
	std::string name_;
	float posX_;
	float posY_;





};