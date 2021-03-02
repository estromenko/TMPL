NAME=tmpl
COMPILER=g++
FLAGS=
FILES=src/lexer/*.cpp src/parser/*.cpp src/*.cpp

.PHONY: compile clean
.all: compile

compile:
	$(COMPILER) $(FLAGS)-o $(NAME) $(FILES)

clean:
	rm -rf $(NAME)
