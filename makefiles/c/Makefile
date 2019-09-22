# Header files
HEADERS = \
	file1.h \
	file2.h

# Object files
OBJECTS = \
	file1.o \
	file2.o

# Compiler
COMPILER = gcc

# GCC compilation flags
GCCFLAGS = -c -g -std=c11 -Wall -Wextra -Werror -Wmissing-declarations

# Output filename
OUTPUT = output

#####
###
#
# 'Make' commands
#
###
#####

# $ 'make' or 'make help'
help:
	@echo "INSTRUCTIONS:"
	@echo "  To test ___, run: make ___"
	@echo "  To test memory allocation, run: make memchk"
	@echo "  To remove compiled output files, run: make clean"

# Executed whenever an object file is out of date
# Symbols:
#   % refers to any character(s)
#   $< refers to the first item in the dependency list
%.o: %.c $(HEADERS)  #TODO Use the path to the .c files, while keeping %.c - e.g. ../src/%.c
	$(COMPILER) $(GCCFLAGS) $<

# $ make <output_name>
<output_name>: $(OBJECTS)
	$(COMPILER) $(OBJECTS) -o $(OUTPUT)
	@echo "To execute the program, run: ./$(OUTPUT)"

# $ make memchk
memchk: $(OBJECTS)
	make <output_name>
	valgrind --leak-check=full ./$(OUTPUT)

# $ make <custom>
<custom>: <source_files>
	<command>
	@echo "Instructions/Explanation"

# $ make clean
# Removes created files
clean:
	rm -f $(OUTPUT) *.o *~
