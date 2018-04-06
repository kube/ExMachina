
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include <stdlib.h>
#include <stdio.h>
#include "SDL.h"

int main(int argc, char **argv)
{
	SDL_Event e;
	SDL_Window *window;
	int should_quit = 0;

	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		printf("ERROR during SDL init: %s\n", SDL_GetError());
	}

	window = SDL_CreateWindow(
		"ExMachina",
		42, 42,
		640, 480,
		SDL_WINDOW_OPENGL);

	if (window == NULL)
	{
		printf("ERROR during SDL window creation: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	while (!should_quit)
	{
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT:
				should_quit = 1;
				break;
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}
