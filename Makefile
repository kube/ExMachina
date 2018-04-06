
      #########.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##."

NAME=exmachina

$(NAME): main.o
	mkdir -p dist
	cc -o dist/$(NAME) `sdl2-config --libs` obj/main.o

main.o:
	mkdir -p obj
	cc -c src/main.c `sdl2-config --cflags` -o obj/main.o

clean:
	rm -rf exmachina
