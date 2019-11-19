# gcc for c program
CC       = gcc
CFLAGS   = -g -Wall
LDFLAGS  =
OBJFILES = hash_new.o hash_new_test.o
TARGET   = hash_new_test

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(TARGET) $(OBJFILES) *~
