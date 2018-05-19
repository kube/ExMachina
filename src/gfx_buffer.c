
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include <stdlib.h>
#include <SDL.h>
#include "gfx_buffer.h"
#include "color.h"

EXM_gfx_buffer *create_gfx_buffer(unsigned int width, unsigned int height)
{
	EXM_gfx_buffer *gfx_buffer;

	gfx_buffer = malloc(sizeof gfx_buffer);
	gfx_buffer->width = width;
	gfx_buffer->height = height;
	gfx_buffer->buffer = malloc(sizeof(EXM_color) * width * height);
}

void clear_gfx_buffer(EXM_gfx_buffer *gfx_buffer)
{
	int i;
	int j;

	for (i = 0;
		 i < gfx_buffer->height * gfx_buffer->height;
		 i++)
	{
		gfx_buffer->buffer = 0;
	}
}

void free_gfx_buffer(EXM_gfx_buffer *gfx_buffer)
{
	free(gfx_buffer->buffer);
	free(gfx_buffer);
}

void render_gfx_buffer(SDL_Renderer *renderer, EXM_gfx_buffer *buffer)
{
	SDL_Texture *texture;
	SDL_Surface *surface;

	surface = SDL_CreateRGBSurfaceFrom(
		buffer->buffer,
		buffer->width, buffer->height,
		NULL, NULL,
		RMASK, GMASK, BMASK, AMASK);

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}
