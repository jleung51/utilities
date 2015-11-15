# Source files
SOURCES  = ../src/multi-variable-analysis.cpp \
           ../src/statistics-analyzer.cpp \
           test.cpp \

# Header files
HSOURCES = print-data-structures.hpp \
           ../include/merge-sort.hpp \
           ../include/single-variable-analysis.hpp \
           ../include/multi-variable-analysis.hpp \
           ../include/statistics-analyzer.hpp \

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
	#   To test the single-variable analysis functions, run: make svar
	#   To remove compiled output files, run: make clean

# $ make svar
svar: $(SOURCES) $(HSOURCES)
	g++ $(CFLAGS) $(SOURCES) -o output
	# To execute the program, run: ./output

# $ make clean
# Removes created files
clean:
	rm -f output *.o *~
