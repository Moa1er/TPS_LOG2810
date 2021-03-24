CC=g++
EXEC=programme
CFLAGS=-lm
# default command, builds an executable called "newton".
# executable can be called with ./newton 49 4
all: $(EXEC)

# link the object files into the executable.
# the -lm option is to tell the linker to include math libraries.
$(EXEC): main.o partie1.o partie2.o
	$(CC) -o $@ $^ $(CFLAGS)

# compile the main.c file into the main.o object file.
main.o: src/main.cpp include/partie1.h include/partie2.h
	$(CC) -o $@ -c $<

partie1.o: src/partie1.cpp include/partie1.h
	$(CC) -o $@ -c $<

partie2.o: src/partie2.cpp include/partie2.h
	$(CC) -o $@ -c $<

# remove the executable and intermediary object files.
clean:
	rm -rf programme *.o

