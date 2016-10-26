
make: RNGrw.c
	gcc RNGrw.c -o rngesus.out

run: make
	./rngesus.out

clean:
	rm -rf *~
