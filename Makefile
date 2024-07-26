CC = clang
CFLAGS = -Wall -g -O2
OBJ = main.o temp_functions.o
TARGET = prog

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c temp_functions.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)
