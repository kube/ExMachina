
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#pragma once

#include "gfx_buffer.h"
#include "point.h"
#include "color.h"

void draw_line(
	EXM_gfx_buffer *buffer,
	EXM_point a,
	EXM_point b,
	EXM_color color);
