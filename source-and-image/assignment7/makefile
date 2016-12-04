OUTPUT1 = mproc1
OUTPUT2 = subproc
OPTS = -g -ggdb -Wall

$(OUTPUT1) : mproc1.o
	gcc -o $(OUTPUT1) $(OPTS) mproc1.o
$(OUTPUT2) : subproc.o
	gcc -o $(OUTPUT2) $(OPTS) subproc.o

mproc1.o : mproc1.c
	gcc -c mproc1.c
subproc.o : subproc.c
	gcc -c subproc.c
