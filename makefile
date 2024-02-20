## ############################################################################
## ################# DONT CHANGE THESE VARIABLES ##############################
## ############################################################################
### SUCCESS CODE FILES ###
INPUT_FILE_NAME_SUCCESS = success_code
INPUT_FOLDER_SUCCESS = input_files/success_code

### LEXIC ERROR FILES ###
INPUT_FILE_NAME_LEXIC_ERROR = lexic_error
INPUT_FOLDER_LEXIC_ERROR = input_files/lexic_error_code

### SINTATIC ERROR FILES ###
INPUT_FILE_NAME_SINTATIC_ERROR = sintatic_error
INPUT_FOLDER_SINTATIC_ERROR = input_files/sintatic_error_code

### SEMANTIC ERROR FILES ###
INPUT_FILE_NAME_SEMANTIC_ERROR = semantic_error
INPUT_FOLDER_SEMANTIC_ERROR = input_files/semantic_error_code
## ############################################################################
## ############################################################################





## ############### CHANGE THESE VARIABLES IF NECESSARY ########################
## ############################################################################
### INPUT CASE (1 - SUCCESS, 2 - LEXIC ERROR, 3 - SINTATIC ERROR, 4 - SEMANTIC ERROR) ###
INPUT_CASE = 1

### OUTPUT FOLDER FOR LOGS (DON'T CHANGE) ###
OUTPUT_FOLDER = output_files
## ############################################################################

build:
	bison -d bison/parser.y -v
	flex flex/lexer.l
	gcc -o lexer parser.tab.c lex.yy.c

compile:
	if [ ! -d $(OUTPUT_FOLDER) ]; then mkdir $(OUTPUT_FOLDER); fi
	@if [ $(INPUT_CASE) = 1 ]; then\
		./lexer $(INPUT_FOLDER_SUCCESS)/$(INPUT_FILE_NAME_SUCCESS).hen;\
	fi
	@if [ $(INPUT_CASE) = 2 ]; then\
		./lexer $(INPUT_FOLDER_LEXIC_ERROR)/$(INPUT_FILE_NAME_LEXIC_ERROR).hen;\
	fi
	@if [ $(INPUT_CASE) = 3 ]; then\
		./lexer $(INPUT_FOLDER_SINTATIC_ERROR)/$(INPUT_FILE_NAME_SINTATIC_ERROR).hen;\
	fi
	@if [ $(INPUT_CASE) = 4 ]; then\
		./lexer $(INPUT_FOLDER_SEMANTIC_ERROR)/$(INPUT_FILE_NAME_SEMANTIC_ERROR).hen;\
	fi

clean:
	rm -f parser.tab.c parser.tab.h parser.output lex.yy.c
	rm -rf $(OUTPUT_FOLDER)/*