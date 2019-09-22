# Header files
HEADERS = \
	file1.hpp \
	file2.hpp

# Object files
OBJECTS = \
	file1.o \
	file2.o

# Compiler
COMPILER = g++
# COMPILER = clang++-3.5

# GCC compilation flags
GCCFLAGS = -c -g -std=c++14 -Wall -Wextra -Werror -Wmissing-declarations

# Clang compilation flags
CLANGFLAGS = -std=c++14 -Werror -fshow-source-location -fshow-column -fcaret-diagnostics -fcolor-diagnostics -fdiagnostics-show-option

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
	@echo "  To remove compiled output files, run: make clean"

# Executed whenever an object file is out of date
# Symbols:
#   % refers to any character(s)
#   $< refers to the first item in the dependency list
%.o: %.cpp $(HEADERS)  #TODO Use the path to the .cpp files, while keeping %.cpp - e.g. ../src/%.cpp
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
