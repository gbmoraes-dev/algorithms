# Algorithm project

# About the project:

This project was made for the exam on the subject of algorithms in the course Computer Science at the University Veiga de Almeida. It consists of creating athlete's cards for a game that are stored in a .csv file. After this step, the cards are transferred to a linked list and placed in alphabetical order.

# To compile the program in gcc you will need the following commands:

1 - gcc -c functions.c -o functions.o

2 - ar rcs libathlete.a functions.o

3 - gcc main.c -o athlete -I./lib -L./lib -lathlete
