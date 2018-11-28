#------------------------------------------------------------------------------
# Makefile for PA2
#------------------------------------------------------------------------------

FLAGS = -std=c99 -Wall
SOURCES = List.c Lex.c
OBJECTS = List.o Lex.o
EXEBIN = Lex

all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)

clean :
	rm -f $(EXEBIN) $(OBJECTS)
