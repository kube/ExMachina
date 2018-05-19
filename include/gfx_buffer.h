
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#pragma once

typedef struct
{
	unsigned int width;
	unsigned int height;
	unsigned int *buffer;
} EXM_gfx_buffer;

EXM_gfx_buffer *create_gfx_buffer(
	unsigned int width,
	unsigned int height);

void free_gfx_buffer(
	EXM_gfx_buffer *buffer);
