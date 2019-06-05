NAME=replace
CPPC=clang++
CPPFLAGS=-Wall -Werror -Wextra
CPPFILES= main.cpp
OFILES=$(CPPFILES:%.cpp=build/%.o)

all: $(NAME)

$(NAME): $(OFILES)
	@$(CPPC) $(CPPFLAGS) $^ -o $@

build/%.o: %.cpp
	@mkdir -p build
	@$(CPPC) $(CPPFLAGS) -c $^ -o $@

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all