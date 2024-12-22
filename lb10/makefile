TARGET = MyProject
CC = gcc

SRC = 10l.c 10lf.c
OBJ = $(patsubst %.c, %.o, $(SRC))

$(TARGET): $(OBJ)
 $(CC) $(OBJ) -o $(TARGET)

%.o: %.c
 $(CC) -c $< -o $@

clean:
 rm -f $(TARGET) *.o