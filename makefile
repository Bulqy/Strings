menu: myint.o main.o
	g++ myint.o main.o -o menu

main.o: main.cpp myint.h 
	g++ -c main.cpp

myint.o: myint.cpp myint.h
	g++ -c myint.cpp

clean:
	rm -f *.o menu
