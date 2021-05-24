alias g++='g++ -std=c++11'

g++ -c ../permutations.cpp
ar crs ../lib/libtask1.a ./permutations.o
g++ ../main.cpp -L../lib/ -ltask1 -o ../lib/task1
rm *.o

../lib/task1 > ../output.txt &