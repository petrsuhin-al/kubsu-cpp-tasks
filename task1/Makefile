export LD_LIBRARY_PATH=.

all: exe clear run

classic: classic.cpp classic.h
	g++ -c -std=c++14 -fpic classic.cpp

complib: classic.cpp
	g++ -shared -Wl,-soname,libdtask1.so.1 -o libdtask1.so ./classic.o
	ldconfig -n .

exe: test/test.cpp complib
	g++ -std=c++14 ./test.cpp -L. -ldtask1 -o dynamic_task1

run: exe
	./dynamic_task1 >output.txt &

clear:
	-rm *.o