# Header files
HEADERS = \
	file1.hpp \
	file2.hpp

# g++ options
GCC = g++ -std=c++14

# g++ compiling flags
GCC-CFLAGS = -c -Wall -Wextra -Wmissing-declarations -Werror

# g++ linking flags
GCC-LFLAGS = -Wall -Wextra -Wmissing-declarations -Werror

# Clang compilation options
CLANG = clang++-3.5 -std=c++14 -Werror -fshow-source-location -fshow-column -fcaret-diagnostics -fcolor-diagnostics -fdiagnostics-show-option

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
	$(GCC) $(GCC-CFLAGS) $<

# $ make <output_name>
<output_name>: file1.o file2.o
	$(GCC) $(GCC-LFLAGS) file1.o file2.o -o $(OUTPUT)
	@echo "To execute the program, run: ./$(OUTPUT)"

# $ make <custom>
<custom>: <source_files>
	<command>
	@echo "Instructions/Explanation"

# $ make clean
# Removes created files
clean:
	rm -f $(OUTPUT) *.o *~
