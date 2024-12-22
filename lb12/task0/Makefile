TARGET = MyProject
CC = gcc

SRC = main.c read_pipe.c write_pipe.c background.c
OBJ = $(patsubst %.c, %.o, $(SRC))


$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)


%.o: %.c
	$(CC) -c $< -o $@


clean:
	rm -f $(TARGET) *.o
