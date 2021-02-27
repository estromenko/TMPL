NAME=tmpl
COMPILER=g++

.all: compile

compile:
	$(COMPILER) -o $(NAME) src/lexer/*.cpp \
							src/*.cpp

clean:
	rm -rf $(NAME)
