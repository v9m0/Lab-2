TARGET = lab
.PHONY: all clean run

all: $(TARGET)
$(TARGET): core.o hex_l.o bin_l.o oct_l.o
	gcc -o $(TARGET) core.o hex_l.o bin_l.o oct_l.o

core.o: core.c
	gcc -c core.c

hex_l.o: hex_l.c
	gcc -c hex_l.c

bin_l.o: bin_l.c
	gcc -c bin_l.c

oct_l.o: oct_l.c
	gcc -c oct_l.c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f main *.o $(TARGET)
