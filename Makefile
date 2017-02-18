# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation
COMPILE = g++
FLAGS =-Wall -Werror -ansi -pedantic
#.DEFAULT_GOAL := a.out
#.PHONY: default
#default: a.out
OBJDIR= bin
# ****************************************************
# Targets needed to bring the executable up to date

	
OBJS = ./bin/Command.o ./bin/Commandinfo.o ./bin/Executer.o


# objdir =bin
# MKPATH = mkdir -p

# $(objdir):
# 	$(MKPATH) $(objdir)
    
    
    
    
all: ./src/main.cpp $(OBJS)

	g++ -g ./src/main.cpp $(OBJS) -o ./bin/rshell


bin/main.o: main.o Command.o Commandinfo.o Executer.o

	g++ -o  ./src/main.cpp ./src/Command.cpp ./src/Commandinfo.cpp ./src/Executer.cpp
	


# The main.o target can be written more simply


#./bin/main.o: ./src/main.cpp ./src/Command.cpp ./src/Commandinfo.cpp ./src/Executer.cpp 
#	 g++ -c ./src/main.cpp 

bin/Command.o: ./src/Command.cpp ./src/Command.h
	g++ -c ./src/Command.cpp

bin/Commandinfo.o: ./src/Commandinfo.cpp ./src/Commandinfo.h 
	g++ -c ./src/Commandinfo.cpp

bin/Executer.o: ./src/Executer.cpp ./src/Executer.h
	g++ -c ./src/Executer.cpp 
	mv *.o ./bin/ 
#clean:
#	rm -rf ./bin/
