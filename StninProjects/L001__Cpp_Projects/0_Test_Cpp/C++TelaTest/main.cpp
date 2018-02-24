//g++ main.cpp -lSDLmain -lSDL -lGL -o out

#include <SDL/SDL.h>
#include "SDL/SDL_opengl.h"
#include <stdio.h>

int main(){

	SDL_Init(SDL_INIT_EVERYTHING);

	//memoria

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	//nome janela

	SDL_WM_SetCaption("TELA", NULL);

	//tamanho janela

	SDL_SetVideoMode(600, 400, 32, SDL_OPENGL);

	//cor

	glClearColor(1,1,1,1);

	//exibiçao janela

	glViewport(0,0,600,400);

	//sombra

	glShadeModel(GL_SMOOTH);

	//2d

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//3d
	glDisable(GL_DEPTH_TEST);

	//LOGICA

	//renderizaçao
	glClear(GL_COLOR_BUFFER_BIT);

	//animaçao
	SDL_GL_SwapBuffers();

	printf("\nFuncionando\n\n");

	SDL_Delay(5000);

	SDL_Quit();

	return 0;

}
