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

	Actor testactor = Actor();

	//LoadImage
	testactor.SetImage("Images/terr.png");
	float yPos = 0;
	float xPos = 0;

	while (!glfwWindowShouldClose(window)) {


		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindTexture(GL_TEXTURE_2D, testactor.GetTexture());

		glm::mat4 trans = glm::mat4(1.0f);
		trans = glm::rotate(trans, glm::radians(180.0f), glm::vec3(0.0, 0.0, 1.0));
		trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));
		trans = glm::translate(trans, glm::vec3(xPos, yPos, 0));


		if (glfwGetKey(window, GLFW_KEY_W) == (GLFW_PRESS || GLFW_REPEAT) ){
			yPos = yPos - 0.005;
		}
		else if (glfwGetKey(window, GLFW_KEY_S) == (GLFW_PRESS || GLFW_REPEAT)) {
			yPos = yPos + 0.005;
		}
		if (glfwGetKey(window, GLFW_KEY_A) == (GLFW_PRESS || GLFW_REPEAT)) {
			xPos = xPos + 0.005;
		}
		else if (glfwGetKey(window, GLFW_KEY_D) == (GLFW_PRESS || GLFW_REPEAT)) {
			xPos = xPos - 0.005;
		}

		testactor.Render();
		unsigned int transformLoc = glGetUniformLocation(testactor.GetShaderProgram(), "transform");
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

		glBindVertexArray(testactor.GetVAO());
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


		glfwSwapBuffers(window);
		glfwPollEvents();

	}



	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

}

