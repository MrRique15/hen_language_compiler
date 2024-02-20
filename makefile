### UNCOMMENT THIS TO TEST SUCCESS CODE (COMMENT OTHERS) ###
INPUT_FILE_NAME = success_code
INPUT_FOLDER = input_files/success_code

### UNCOMMENT THIS TO TEST LEXIC ERROR (COMMENT OTHERS) ###
# INPUT_FILE_NAME = lexic_error
# INPUT_FOLDER = input_files/lexic_error_code

### UNCOMMENT THIS TO TEST SINTATIC ERROR (COMMENT OTHERS) ###
# INPUT_FILE_NAME = sintatic_error
# INPUT_FOLDER = input_files/sintatic_error_code

### UNCOMMENT THIS TO TEST SEMANTIC ERROR (COMMENT OTHERS) ###
# INPUT_FILE_NAME = semantic_error
# INPUT_FOLDER = input_files/semantic_error_code



### OUTPUT FOLDER FOR LOGS (DON'T CHANGE) ###
OUTPUT_FOLDER = output_files


build:
	bison -d bison/parser.y -v
	flex flex/lexer.l
	gcc -o lexer parser.tab.c lex.yy.c

compile:
	./lexer $(INPUT_FOLDER)/$(INPUT_FILE_NAME).hen
