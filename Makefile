# gcc for c program
CC       = gcc
CFLAGS   = -g -Wall
LDFLAGS  =
OBJFILES = hash.o main.o
TARGET   = hashtest

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(TARGET) $(OBJFILES) *~
