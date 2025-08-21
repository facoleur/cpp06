CFLAGS= -g -Wall -Wextra -Werror -std=c++98

SRCS= main.cpp Serializer.cpp

OBJS= $(SRCS:.cpp=.o)
NAME= serialize
all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


