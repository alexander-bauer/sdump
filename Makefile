CFLAGS=-Wall -g

.DEFAULT_GOAL := sdump

sdump:
	cc main.c -o sdump

clean:
	rm -f *.o sdump