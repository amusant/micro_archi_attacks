SRC=flush_reload.c
all:
	gcc   -c -o  flush_reload.o flush_reload.c
	gcc -o test victim.o flush_reload.o

launch:
	gem5.opt ../configs/two_level.py ./test
	

clean:
	rm -rf flush_reload.o 
	rm -rf a.out m5out test

	
