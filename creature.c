#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h> // Needed for glext.h
#include <GL/glext.h> // For framebuffer funtion pointer types, i think it's necessary? idk man opengl is crazy
#include <GLFW/glfw3.h>
#include "lodepng.h"

#define SLEEP 1

void handle_terminate(int signal) {
	exit(EXIT_SUCCESS);
}

int main(int argc, char* argv[]) {
	signal(SIGINT, handle_terminate);
	srand(time(NULL));

	// load image
	if (argc < 2) {
		fprintf(stderr, "ERROR: no image specified.\n");
		exit(EXIT_FAILURE);
	}
	const char* filename = argv[1];

	unsigned char* img;
	unsigned int imgw, imgh;
	int err = lodepng_decode_file(&img, &imgw, &imgh, filename, LCT_RGBA, 8);
	if (err) {
		fprintf(stderr, "ERROR: could not load image.\n");
		exit(EXIT_FAILURE);
	}

	// glfw init
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: failed to init GLFW.\n");
		exit(EXIT_FAILURE);
	}
	atexit(glfwTerminate);

	// getting screen size
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int screenw = mode->width;
	int screenh = mode->height;

	// creating windows
	while (1) {
		GLFWwindow* win = glfwCreateWindow(imgw, imgh, "", NULL, NULL);
		if (!win) {
			fprintf(stderr, "ERROR: failed to create window.\n");
			exit(EXIT_FAILURE);
		}
		glfwMakeContextCurrent(win);

		glfwSetWindowPos(win, rand()%screenw, rand()%screenh); // randomize position
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // make it floating

		glRasterPos2f(-1,1);
		glPixelZoom(1,-1);
		glDrawPixels(imgw, imgh, GL_RGBA, GL_UNSIGNED_BYTE, img); // drawing
		glfwSwapBuffers(win);

		sleep(SLEEP);
	}

	exit(EXIT_SUCCESS);
}

