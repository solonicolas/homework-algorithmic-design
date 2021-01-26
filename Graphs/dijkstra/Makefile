EXE = main.x
DIR = ../../Heaps/basic_heaps

CFLAGS = -I include -I $(DIR)/include

BINHEAP = -lbinheap -l common -L $(DIR)

all: $(EXE)

%.o: %.c
	gcc -w -c $< -o $@ $(CFLAGS) $(BINHEAP)

src/graph.o: include/graph.h
src/node.o: include/node.h
src/list.o: include/list.h
src/queue_array.o: include/queue_array.h

main.o : src/graph.o src/node.o src/list.o src/queue_array.o

main.x: main.o src/graph.o src/node.o src/list.o src/queue_array.o
	gcc $^ -o $@ $(BINHEAP)

clean:
	rm -rf *.o src/*.o *.x

.PHONY: clean all