INPUT_FILE_NAME = example
INPUT_FOLDER = input_files
OUTPUT_FOLDER = output_files


lexical_check:
	flex lexic/lexer.l
	gcc lex.yy.c -o lexer
	./lexer $(INPUT_FOLDER)/$(INPUT_FILE_NAME).hen
