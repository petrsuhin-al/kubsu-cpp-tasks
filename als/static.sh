alias g++='g++ -std=c++11'

g++ -c ./gradient.cpp ./errors.cpp ./linear_regression.cpp
ar crs ./libals.a ./errors.o ./linear_regression.o ./gradient.o
g++ ./main.cpp -L. -lals -o ./als

g++ main.cpp -L. -lals -o ./als

#-std=c++14 \
# -I /usr/local/Cellar/python/3.7.3/Frameworks/Python.framework/Versions/3.7/include/python3.7m \
# -L /usr/local/Cellar/python/3.7.3/Frameworks/Python.framework/Versions/3.7/lib \
# -lpython3.7m

rm *.o

./als > ./output.txt &