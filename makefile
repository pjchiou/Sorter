CC = gcc
flag = -Wall
OBJ = main.o array.o sort.o

all: $(OBJ)
	$(CC) $(flag) -o main $(OBJ)

%.o: %.c
	$(CC) $(flag) -c $<

clean: 
	rm main *.o
