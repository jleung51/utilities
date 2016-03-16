# Header files
HEADERS = \
	file1.h \
	file2.h

# gcc options
GCC = gcc -std=c11 -Wall -Wextra -Wmissing-declarations -Werror

# Compiler options
CFLAGS = -c

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
	$(GCC) $(CFLAGS) $<

# $ make <output_name>
<output_name>: file1.o file2.o
	$(GCC) file1.o file2.o -o $(OUTPUT)
	@echo "To execute the program, run: ./$(OUTPUT)"

# $ make memchk
memchk: file1.o file2.o
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
