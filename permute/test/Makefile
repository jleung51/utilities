# Source files for merge sort (vector) testing
S_SOURCES = test_merge_sort.cpp \

# Source files for permute testing
P_SOURCES  = ../src/permute.cpp \
           test_permute.cpp \

# Header files
HSOURCES = ../include/merge_sort_vector.hpp \
           ../include/permute.hpp \

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
	#   To test MergeSortVector(), run: make sort
	#   To test Permute(), run: make permute
	#   To remove compiled output files, run: make clean

# $ make sort
sort: $(S_SOURCES) $(HSOURCES)
	g++ $(CFLAGS) $(S_SOURCES) -o output
	# To execute the progarm, run: ./output

# $ make permute
permute: $(P_SOURCES) $(HSOURCES)
	g++ $(CFLAGS) $(P_SOURCES) -o output
	# To execute the program, run: ./output

# $ make clean
# Removes created files
clean:
	rm -f output *.o *~
