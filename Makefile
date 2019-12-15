# Automatic variables
# $@: the target filename.
# $*: the target filename without the file extension.
# $<: the first prerequisite filename.
# $^: the filenames of all the prerequisites, separated by spaces, discard duplicates.
# $+: similar to $^, but includes duplicates.
# $?: the names of all prerequisites that are newer than the target, separated by spaces.


# gcc for c program
CC       = gcc

# make rule for gcc when compile
CFLAGS   = c99 -Wall -pedantic -g3
LDFLAGS  =
OBJFILES = hello_word.o hello_library.o
TARGET   = hello_word

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $@ $^
	echo "I just build hello world! Hooray!"

# pattern matching character % as the filename 
%o: %.c %.h
	$(CC) -c $^

test: 	$(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o
