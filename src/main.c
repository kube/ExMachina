
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
#include <SDL.h>

#include "color.h"
#include "gfx_buffer.h"

#define BUFFER_WIDTH 480
#define BUFFER_HEIGHT 640

static void
initialize_surface(SDL_Surface *surface)
{
	int i;
	int j;
	EXM_gfx_buffer *buffer;
	EXM_color colour;

	colour.red = 0x00;
	colour.green = 0x00;
	colour.blue = 0x00;
	colour.alpha = 0xFF;

	SDL_LockSurface(surface);
	buffer = surface->pixels;

	j = 0;
	while (j < surface->h)
	{
		i = 0;
		while (i < surface->w)
		{
			colour.red = 255 *
						 (i * i + j * j) /
						 (surface->h * surface->h + surface->w * surface->w);
			buffer->buffer[surface->w * j + i] = colour.value;
			i++;
		}
		j++;
	}

	SDL_UnlockSurface(surface);
}

void render_surface(SDL_Renderer *renderer, SDL_Surface *surface)
{
	SDL_Texture *texture;

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

int main()
{
	SDL_Event e;
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Surface *surface;
	int should_quit = 0;

	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		printf("ERROR during SDL init: %s\n", SDL_GetError());
	}

	window = SDL_CreateWindow(
		"ExMachina",
		42, 42,
		640, 480,
		0);

	if (window == NULL)
	{
		printf("ERROR during SDL window creation: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	// Create a surface to write directly in buffer
	surface = SDL_CreateRGBSurface(
		0, BUFFER_WIDTH, BUFFER_HEIGHT, 32, RMASK, GMASK, BMASK, AMASK);
	initialize_surface(surface);

	// Create render for window and render surface in it
	renderer = SDL_CreateRenderer(window, -1, 0);
	render_surface(renderer, surface);

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
