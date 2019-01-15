CC = gcc
flag = -Wall -O0
OBJ = main.o array.o sort.o

all: $(OBJ)
	$(CC) $(flag) -o main $(OBJ)

output: main.c array.c sort.c
	$(CC) $(flag) -DOUTPUT -o main main.c array.c sort.c

debug: main.c array.c sort.c
	$(CC) $(flag) -g -o main main.c array.c sort.c

%.o: %.c
	$(CC) $(flag) -c $<

clean: 
	rm main *.o
