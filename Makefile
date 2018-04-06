
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
	cc -o dist/$(NAME) obj/main.o

main.o:
	mkdir -p obj
	cc -c src/main.c -o obj/main.o

clean:
	rm -rf exmachina
