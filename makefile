signals: signals.c
	gcc -o signals signals.c

run: signals
	./signals

clean:
	rm signals
	rm sigfile.txt
	rm *~
