OUTPUT = mtest
OPTS = -g -ggdb -Wall

$(OUTPUT) : mtest.o boo.o foo.o bar.o a.h
	gcc -o $(OUTPUT) mtest.o boo.o foo.o bar.o

mtest.o : mtest.c a.h
	gcc -c mtest.c
boo.o : boo.c a.h
	gcc -c boo.c
foo.o : foo.c a.h
	gcc -c foo.c
bar.o : bar.c a.h
	gcc -c bar.c
