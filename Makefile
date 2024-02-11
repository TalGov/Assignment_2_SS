CC = gcc
CFLAGS = -Wall

all: my_graph my_Knapsack

my_graph: main.o my_mat.o
	$(CC) $(CFLAGS) $^ -o $@

my_Knapsack: my_Knapsack.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c my_mat.h
	$(CC) $(CFLAGS) -c main.c -o main.o

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c my_mat.c -o my_mat.o

my_Knapsack.o: my_Knapsack.c
	$(CC) $(CFLAGS) -c my_Knapsack.c -o my_Knapsack.o

clean:
	rm -f *.o my_graph my_Knapsack
