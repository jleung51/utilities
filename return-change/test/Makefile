# Source files
SOURCES  = ../src/change.cpp \
           test.cpp

# Header files
HSOURCES = ../include/change.hpp

# Compiler options
CFLAGS = -std=c++11 -g -Wall

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
	#   To test ReturnChange(), run: make output
	#   To remove compiled output files, run: make clean

# $ make output
output: $(SOURCES) $(HSOURCES)
	g++ $(CFLAGS) $(SOURCES) -o output
	# To execute the program, run: $ ./output

# $ make clean
# Removes created files
clean:
	rm -f output *.o *~
