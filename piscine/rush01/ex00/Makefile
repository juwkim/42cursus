CC = gcc
FLAGS = -Wall -Wextra -Werror
TARGET = rush-01
OBJECTS = main.o recursive.o validation_1.o validation_2.o error_check.o util.o
$(SRC:.o.c)

$(TARGET):	$(OBJECTS)
	$(CC) $(FLAGS) -o $@ $^

clean:
	rm -f $(OBJECTS) $(TARGET)
