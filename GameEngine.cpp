#include <iostream>

#include "GameEngine.hpp"
#include "InitException.hpp"

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
const char * WINDOW_TITLE = "Game Engine";

void GameEngine::init() {
	glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	#endif

	window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, WINDOW_TITLE, NULL, NULL);
	
	if (window == NULL)
	{
		throw InitException("Failed to create GLFW window");
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, 
		[](GLFWwindow* window, int width, int height){
			glViewport(0, 0, width, height);
		});

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		throw InitException("Failed to initialise GLAD");
	}    
}

void GameEngine::run() {
	while(!glfwWindowShouldClose(window))
	{
		processInput();

		glClearColor(0.2f, 0.8f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();    
	}
}

void GameEngine::shutdown() {
	glfwTerminate();
}

void GameEngine::processInput()
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}