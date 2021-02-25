
NAME=tmpl
COMPILER=g++

.all: compile

compile:
	$(COMPILER) -o $(NAME) src/*.cpp

clean:
	rm -rf $(NAME)
