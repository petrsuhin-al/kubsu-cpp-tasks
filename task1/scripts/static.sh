alias g++='g++ -std=c++11'

g++ -c ../classic.cpp ../blocks.cpp
ar crs ../lib/libtask1.a ./classic.o ./blocks.o
g++ ../test/test.cpp -L../lib/ -ltask1 -o ../lib/task1
rm *.o

../lib/task1 > ../test/output.txt &