alias g++='g++ -std=c++11'
g++ -c -std=c++14 classic.cpp

ar crs ./lib/libtask1.a ./classic.o

g++ test.cpp -L. -ltask1 -o ./lib/task1

rm *.o

./task1 >output.txt &