#include <iostream>
#include <cstring>
#include "myint.h"

using namespace std;

int main() {
	MyInt Number;

	MyInt Numb("12345");
	MyInt Numb2("55555");
	MyInt N(1010101010);
	
	cout << N << endl;
	cout << Numb << endl;
	MyInt Test =  Numb + Numb2;

	cout << Test;
		
	





	return 0;
}
