export LD_LIBRARY_PATH=.


all: exe clear run

errors.o: errors.cpp errors.h
	g++ -std=c++11 -c -fpic errors.cpp

gradient.o: gradient.cpp gradient.h
	g++ -std=c++11 -c -fpic gradient.cpp

linear_regression.o: linear_regression.cpp linear_regression.h
	g++ -std=c++11 -c -fpic linear_regression.cpp

complib: errors.o gradient.o linear_regression.o
	g++ -std=c++11 -shared -fPIC -Wl,-soname,libdals.so.1 -o libdals.so ./errors.o ./gradient.o ./linear_regression.o
	ldconfig -n .

exe: main.cpp complib
	g++ -std=c++11 ./main.cpp -L. -ldals -o dynamic_als

plot: run
	gnuplot --persist  plot.sh

run: exe
	./dynamic_als >output.txt &

clear:
	-rm *.o
