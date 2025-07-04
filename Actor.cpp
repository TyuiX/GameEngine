#include "Actor.h"
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "stb_image.h"



//Shaders
const char* vertexShaderSource = "#version 330 core\n"
"layout(location = 0) in vec3 aPos;\n"
"layout(location = 1) in vec2 aTexCoord;\n"
"out vec2 TexCoord;\n"
"uniform mat4 transform;\n"
"void main()\n"
"{\n"
"	gl_Position = transform * vec4(aPos, 1.0f);\n"
"	TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n"
"}\n\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"in vec2 TexCoord;\n"
"uniform sampler2D ourTexture;\n"
"void main()\n"
"{\n"
"	FragColor = texture(ourTexture, TexCoord);\n"
"}\n\0";

Actor::Actor() {
	name = "";
	visible = false;

	//object/Player
	float square[] = {
		 0.5f,  0.5f, 0.0f,   1.0f, 1.0f,   // top right
		 0.5f, -0.5f, 0.0f,   1.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f,   // bottom left
		-0.5f,  0.5f, 0.0f,   0.0f, 1.0f    // top left 
	};
	unsigned int points[] = {
		0, 1, 3,
		1, 2, 3
	};
	shaderProgram = glCreateProgram(); 
	//Vertex Shader
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	//FragmentShader
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	//combine/using Shader
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	//Delete once linked
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	//Buffer
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &sQ);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(square), square, GL_DYNAMIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sQ);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(points), points, GL_DYNAMIC_DRAW);
	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// texture coord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

void Actor::SetName(std::string newName) {
    name = newName;
}

int Actor::SetVisible() {
    if (visible) return 1;
    visible = true;
    return 0;
}

int Actor::SetInvisible() {
    if (!visible) return 1;
    visible = false;
    return 0;
}
int Actor::SetImage(char * path) {
	int out = 1;
	int width, height, nrChannels;
	unsigned char* imgData = stbi_load(path, &width, &height, &nrChannels, 0);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	if (imgData)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imgData);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{	
		//return 0 let it know it failed
		out = 0;
	}
	stbi_image_free(imgData);
	return out;
	
}
unsigned int Actor::GetTexture() {
	return texture;
}
unsigned int Actor::GetShaderProgram() {
	return shaderProgram;
}
unsigned int Actor::GetVAO() {
	return VAO;
}
// Leave Update and Render empty or implement them if needed
void Actor::Update() {}
void Actor::Render() {
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
}