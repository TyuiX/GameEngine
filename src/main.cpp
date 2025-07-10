#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Player.h"
#include "Actor.h"

#include <lib/glm/glm.hpp>
#include <lib/glm/gtc/matrix_transform.hpp>
#include <lib/glm/gtc/type_ptr.hpp>

#include <gameHandler.h>




void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);




int main() { 
	std::cout << "hello" << std::endl; 

	
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



	//Window Creation
	GLFWwindow* window = glfwCreateWindow(1280, 720, "main", NULL, NULL);

	glfwSetKeyCallback(window, key_callback);

	if (window == NULL) {
		std::cout << "FAIL" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	gladLoadGL();
	glViewport(0, 0, 1280, 720);

	Actor testactor;
	Actor testactor2;
	gameHandler game;
	testactor2.setPlayer();

	//LoadImage
	testactor.SetImage("Images/terr.png");
	testactor2.SetImage("Images/Circle-PNG-File.png");
	float yPos = 0;
	float xPos = 0;
	testactor.SetName("test");
	game.addState();
	game.addActor(testactor, 0, 0);
	game.addActor(testactor2, 0, 1);
	while (!glfwWindowShouldClose(window)) {


		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		game.renderState(window);
		//testactor.Render(window);
		//testactor2.Render(window);




		glfwSwapBuffers(window);
		glfwPollEvents();

	}



	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

}

