#pragma once
#include <string>
class Actor
{
protected:
	std::string name;
	bool visible = false;
	//place holder var for decal or image not sure what lib load render
	// imagepointerClass image=;

public:
	virtual ~Actor() = default;
	//function to update the state of the class
	virtual void Update();
	//render the actor into the game
	virtual void Render();
	//set new name 
	virtual void SetName(std::string newName) {
		name = newName;
	}
	//set visibility state
	virtual int SetVisible() {
		if (visible) {
			return 1;
		}
		visible = true;
		return 0;
	}
	virtual int SetInvisible() {
		if (!visible) {
			return 1;
		}
		visible = false;
		return 0;
	}

};

