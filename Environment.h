#include <string>
class Environment
{
protected:
	int gamestate = 0;

	//place holder var for decal or image not sure what lib load render
	// imagepointerClass image=;
	//function to update the state of the class
	virtual void Update();
	//render the actor into the game
	virtual void Render();
};

