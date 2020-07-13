CC = clang++
NAME = container
BUILD_DIR ?= ./build
SRC_DIRS ?= ./test
MKDIR_P ?= mkdir -p
INC = -Iinc -Icontainers
FLAG = -Wall -Wextra -Werror

SRC := $(shell find $(SRC_DIRS) -name *.cpp)

OBJS := $(SRC:%=$(BUILD_DIR)/%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(INC) $(OBJS) $(FLAG) -o $(NAME)

$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CC) $(INC) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
	rm -f *.txt

re : fclean
	make all

.PHONY: all clean fclean re