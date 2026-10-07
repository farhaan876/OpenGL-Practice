#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>

using namespace std;

int main()
{
	// Initialise glfw
	glfwInit();
	//Tell GLFW what version of opengl is being used
	// this case it is 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// so it means we only have the modern functions
	// Tell OpenGL we are using the core profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// create a glfw window object of 800 by 800 pixels naming it YoutubeOpenGL
	GLFWwindow* window = glfwCreateWindow(800, 800, "I made this", NULL, NULL);
	//error for checking if the window fails to create
	if (window == NULL)
	{
		cout << "Failed to create a window" << endl;
		glfwTerminate();
		return -1;
	}
	// introduce the window into the current context
	glfwMakeContextCurrent(window);
	//Load glad so it configures opengl 
	gladLoadGL();
	//specify the viewport of opengl in the window
	glViewport(0, 0, 800, 800);
	// viewport goes from x=800 to y=800
	//specify the color of the background
	glClearColor(1.0f, 0.5f, 0.0f, 1.0f);
	//clean the back back buffer and assign the new color to it.
	glClear(GL_COLOR_BUFFER_BIT);
	//swap the back buffer with the front buffer
	// main while loop
	while (!glfwWindowShouldClose(window)) // 
	{
		//put the cmath package at the top for recognising std::sin
		// Inside your main GLFW render loop
		// Get the absolute time elapsed
		double time = glfwGetTime();
		// calculate smooth,. independent 0.0 to 1.0 values for each channel
		float r = (sin(time) + 1.0f) / 2.0f;
		float g = (sin(time + 2.0f) +1.0f)/2.0f;
		float b = (sin(time * 1.5f) + 1.0f)/2.0f;
		// clearing the screen with our evolving color palette.
		glClearColor(r, g, b, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
		//take care of all glfwevents
	// delete window before ending the program
	glfwDestroyWindow(window);
	//terminate glfw before ending the program
	glfwTerminate();
	// return statement. 
	return 0;
}