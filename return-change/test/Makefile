# Source files
SOURCES  = ../return_change/change.cpp test.cpp

# Header files
HSOURCES = ../return_change/change.hpp

# Compiler options
CFLAGS = -std=c++11 -g -Wall

#####
###
#
# 'Make' commands
#
###
#####

# $ make
out: $(SOURCES) $(HSOURCES)
	g++ $(CFLAGS) $(SOURCES) -o out
	# To execute the program, run: $ ./out

# $ make clean
# Removes created files
clean:
	rm -f out *.o *~
