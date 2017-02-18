# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

COMPILE = g++
FLAGS =-Wall -Werror -ansi -pedantic

# ****************************************************
# Targets needed to bring the executable up to date

./src/main: ./src/main.o ./src/Command.o ./src/Commandinfo.o ./src/Executer.o 
	g++ -o ./src/main.o ./src/Command.o ./src/Commandinfo.o ./src/Executer.o

# The main.o target can be written more simply

./src/main.o: ./src/main.cpp ./src/Command.h ./src/Commandinfo.h ./src/Executer.h
	g++ -c ./src/main.cpp 

./src/Command.o: ./src/Command.cpp ./src/Command.h
		g++ -c Command.cpp

./src/Commandinfo.o: ./src/Commandinfo.cpp ./src/Commandinfo.h 
	g++ -c Commandinfo.cpp

./src/Executer.o: ./src/Executer.cpp ./src/Executer.h
		g++ -c ./src/Executer.cpp 

