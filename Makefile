CFLAGS=-Wall -g

.DEFAULT_GOAL := sdump

sdump:
	cc main.c cap.c -o sdump -lpcap

clean:
	rm -f *.o sdump