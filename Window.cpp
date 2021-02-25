﻿#include "Window.h"

#include "Application.h"


Window::Window(const int width, const int height, const char* title, App* app) {
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
	
	window = glfwCreateWindow(width, height, title, nullptr, nullptr);

}

Window::~Window() {
	glfwDestroyWindow(window);

	glfwTerminate();
}

std::pair<int, int> Window::getFramebufferSize() const {
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	return std::pair<int, int>(width, height);
}

GLFWwindow* Window::getGLFWwindow() const {
	return window;
}

bool Window::windowShouldClose() const {
	return glfwWindowShouldClose(window);
}

void Window::getCursorPos(double* xpos, double* ypos) const {
	glfwGetCursorPos(window, xpos, ypos);
}
