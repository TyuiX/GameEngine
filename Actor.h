#pragma once
#include <string>
class Actor
{
protected:
	std::string name;
	bool visible;
	unsigned int shaderProgram;
	unsigned int texture;
	unsigned int VBO, VAO, sQ;
	//place holder var for decal or image not sure what lib load render
	// imagepointerClass image=;

public:
	Actor();
	virtual ~Actor() = default;
	//function to update the state of the class
	virtual void Update();
	//render the actor into the game
	virtual void Render();
	//set new name 
	virtual void SetName(std::string newName);
	//set visibility state
	virtual int SetVisible();
	virtual int SetInvisible();
	virtual int SetImage(char * path);
	virtual unsigned int GetTexture();
	virtual unsigned int GetShaderProgram();
	virtual unsigned int GetVAO();
};

