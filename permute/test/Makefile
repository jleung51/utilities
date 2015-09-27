# Source files
SOURCES  = ../src/permute.cpp \
           test.cpp

# Header files
HSOURCES = ../include/permute.hpp

# Compiler options
CFLAGS = -std=c++14 -g -Wall

#####
###
#
# 'Make' commands
#
###
#####

# $ 'make' or 'make help'
help:
	# INSTRUCTIONS:
	#   To test Permute(), run: make permute
	#   To remove compiled output files, run: make clean

# $ make output
permute: $(SOURCES) $(HSOURCES)
	g++ $(CFLAGS) $(SOURCES) -o output
	# To execute the program, run: ./output

# $ make clean
# Removes created files
clean:
	rm -f output *.o *~
