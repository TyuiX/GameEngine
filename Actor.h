#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "stb_image.h"
#include <lib/glm/glm.hpp>
#include <lib/glm/gtc/matrix_transform.hpp>
#include <lib/glm/gtc/type_ptr.hpp>
#include <string>
class Actor
{
protected:
	std::string name;
	bool visible;
	bool player;
	unsigned int shaderProgram;
	unsigned int texture;
	unsigned int VBO, VAO, sQ;
	float posX, posY;
	//place holder var for decal or image not sure what lib load render
	// imagepointerClass image=;

public:
	Actor();
	virtual ~Actor() = default;
	//function to update the state of the class
	virtual void Update();
	//render the actor into the game
	virtual void Actor::Render(GLFWwindow* window);
	//set new name 
	virtual void SetName(std::string newName);
	//set visibility state
	virtual int SetVisible();
	virtual int SetInvisible();
	virtual int SetImage(char * path);
	virtual unsigned int GetTexture();
	virtual unsigned int GetShaderProgram();
	virtual unsigned int GetVAO();
	void setX(float x);
	void setY(float y);
	float getX();
	float getY();
	void setPlayer();
};

