
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include <SDL.h>
#include "line.h"
#include "color.h"
#include "point.h"
#include "gfx_buffer.h"

static void
EXM_draw_dot(
	EXM_gfx_buffer *buffer,
	unsigned int x,
	unsigned int y,
	EXM_color color)
{
	if (x < buffer->width && y < buffer->height)
		buffer->buffer[y * buffer->width + x] = color.value;
}

static void
draw_loop_x(
	EXM_gfx_buffer *buffer,
	EXM_point start,
	EXM_point end,
	EXM_color color)
{
	float derivative;
	EXM_point current;

	current.x = (int)start.x;
	current.y = start.y;
	derivative = (end.y - start.y) / (end.x - start.x);

	while ((int)current.x <= (int)end.x)
	{
		EXM_draw_dot(
			buffer,
			current.x,
			current.y,
			color);

		current.x = current.x + 1;
		current.y = current.y + derivative;
	}
}

static void
draw_loop_y(
	EXM_gfx_buffer *buffer,
	EXM_point start,
	EXM_point end,
	EXM_color color)
{
	float derivative;
	EXM_point current;

	current.x = start.x;
	current.y = (int)start.y;
	derivative = (end.x - start.x) / (end.y - start.y);

	while ((int)current.y <= (int)end.y)
	{
		EXM_draw_dot(
			buffer,
			current.x,
			current.y,
			color);

		current.x = current.x + derivative;
		current.y = current.y + 1;
	}
}

void draw_line(
	EXM_gfx_buffer *buffer,
	EXM_point a,
	EXM_point b,
	EXM_color color)
{
	if (abs((int)(a.x - b.x)) <= abs((int)(a.y - b.y)))
	{
		if (b.y < a.y)
		{
			draw_loop_y(buffer, b, a, color);
		}
		else
		{
			draw_loop_y(buffer, a, b, color);
		}
	}
	else
	{
		if (b.x < a.x)
		{
			draw_loop_x(buffer, b, a, color);
		}
		else
		{
			draw_loop_x(buffer, a, b, color);
		}
	}
}
