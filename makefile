INPUT_FILE_NAME = example
INPUT_FOLDER = input_files
OUTPUT_FOLDER = output_files


lexical_check:
	bison -d bison/parser.y
	flex flex/lexer.l
	gcc -o lexer parser.tab.c lex.yy.c
	./lexer $(INPUT_FOLDER)/$(INPUT_FILE_NAME).hen
	rm lexer
