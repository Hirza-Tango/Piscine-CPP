NAME=megaphone
CPPC=clang++
CPPFLAGS=-Wall -Werror -Wextra
MAIN=megaphone.cpp
CPPFILES=
OFILES=$(CPPFILES:%.cpp=build/%.o)

all: $(NAME)

$(NAME): $(MAIN) $(OFILES)
	$(CPPC) $(CPPFLAGS) $^ -o $@

build/%.o: %.cpp
	@mkdir -p build
	$(CPPC) $(CPPFLAGS) -c $^ -o $@
clean:
	@rm -f $(OFILES)
fclean: clean
	@rm -f $(NAME)

re: fclean all
