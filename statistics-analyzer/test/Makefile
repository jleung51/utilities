# Source files for sorting
SOURCES_SORT = test-sort.cpp \

# Header files for sorting
HSOURCES_SORT = data-structure-operations.hpp \
                ../include/merge-sort.hpp \

# Source files for single-variable analysis
SOURCES_SVAR = ../src/multi-variable-analysis.cpp \
                ../src/statistics-analyzer.cpp \
                test-svar.cpp \

# Header files for single-variable analysis
HSOURCES_SVAR = data-structure-operations.hpp \
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
	#   To test the sort algorithm, run: make sort
	#   To test the single-variable analysis functions, run: make svar
	#   To remove compiled output files, run: make clean

# $ make sort
sort: $(HSOURCES_SORT)
	g++ $(CFLAGS) $(SOURCES_SORT) -o output
	# To execute the program, run: ./output

# $ make svar
svar: $(SOURCES_SVAR) $(HSOURCES_SVAR)
	g++ $(CFLAGS) $(SOURCES_SVAR) -o output
	# To execute the program, run: ./output

# $ make clean
# Removes created files
clean:
	rm -f output *.o *~
