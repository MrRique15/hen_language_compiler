INPUT_FILE_NAME = example
INPUT_FOLDER = input_files
OUTPUT_FOLDER = output_files


build:
	bison -d bison/parser.y -v
	flex flex/lexer.l
	gcc -o lexer parser.tab.c lex.yy.c

compile:
	./lexer $(INPUT_FOLDER)/$(INPUT_FILE_NAME).hen
