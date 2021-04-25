#if [ False ]
#then
#
#    # g++ -c -fpic dot.cpp
#    # g++ -c -fpic gauss.cpp
#    # g++ -c -fpic prog.cpp
#
#    # # cоздаём файл библиотеки
#    # g++ -shared -Wl,-soname,libd1lab.so.1 -o libd1lab.so.1.0  ./dot.o ./gauss.o ./prog.o
#
#    # mkdir dynamic_lib
#
#    # cp libd1lab.so.1.0 ./dynamic_lib/libd1lab.so.1.0
#
#    # ldconfig -n ./dynamic_lib
#
#    # # cоздадим файл libd1lab.so как мягкую ссылку
#    # ln -s ./dynamic_lib/libd1lab.so.1.0 ./dynamic_lib/libd1lab.so
#
#
#    # export LD_LIBRARY_PATH=./dynamic_lib
#
#    # # compile
#    # g++ ./test.cpp -L ./dynamic_lib -ld1lab -o dynamic_1lab
#    echo "RUNNING"
#fi

alias g++='g++ -std=c++11'

g++ -c -fpic classic.cpp

g++ -shared -Wl,-soname,libdtask1.so.1 -o libdtask1.so ./classic.o

ldconfig -n ./lib

export LD_LIBRARY_PATH=./lib

g++ ./test/test.cpp -L./lib/ -ldtask1 -o ./lib/dynamic_task1

rm *.o

./lib/dynamic_task1 > ./test/output.txt &