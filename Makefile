
      #########.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##."

NAME = exmachina

SRC_DIR = src
OBJ_DIR = obj
DIST_DIR = dist

CFLAGS = -Wall -Werror -Wextra `sdl2-config --cflags`

SOURCES=\
	line.c \
	main.c \

OBJECTS=$(addprefix $(OBJ_DIR)/,$(SOURCES:.c=.o))

# Colors
NO_COLOR     := \x1b[0m
OK_COLOR     := \x1b[32;01m
ERROR_COLOR  := \x1b[31;01m
WARN_COLOR   := \x1b[33;01m
SILENT_COLOR := \x1b[30;01m


# Basic Rules
.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJECTS)
	@mkdir -p $(DIST_DIR)
	@printf "$(SILENT_COLOR)"
	@printf "LINKING EXECUTABLE "
	@printf "$(NO_COLOR)"

	@$(CC) \
		-g \
		`sdl2-config --libs` \
		-o $(DIST_DIR)/$(NAME) \
		$^ \
		&& echo "$(OK_COLOR)✓"

	@printf "$(NO_COLOR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf "$(SILENT_COLOR)"
	@printf "COMPILE "
	@printf "$(NO_COLOR)"
	@printf "$@ "
	@printf "$(SILENT_COLOR)"
	@printf "$(NO_COLOR)"

	@$(CC) \
		-g \
		$(CFLAGS) \
		-c $< -Iinclude \
		-o $@ \
		&& echo "$(OK_COLOR)✓"

	@printf "$(NO_COLOR)"

clean:
	@printf "$(SILENT_COLOR)"
	@printf "CLEAN OBJECTS "
	@printf "$(NO_COLOR)"
	@rm -rf $(OBJ_DIR) && echo "$(OK_COLOR)✓"
	@printf "$(NO_COLOR)"

fclean: clean
	@printf "$(SILENT_COLOR)"
	@printf "CLEAN DIST "
	@printf "$(NO_COLOR)"
	@rm -rf $(DIST_DIR) && echo "$(OK_COLOR)✓"
	@printf "$(NO_COLOR)"

re: fclean all
