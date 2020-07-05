#include <iostream>
using namespace std;

class MyInt
{
	// return concatenation of two strings
	friend MyInt operator+ (const MyInt& x, const MyInt& y);

	friend bool operator< (const MyInt& x, const MyInt& y);
	friend bool operator> (const MyInt& x, const MyInt& y);
	friend bool operator<= (const MyInt& x, const MyInt& y);
	friend bool operator>= (const MyInt& x, const MyInt& y);
	friend bool operator== (const MyInt& x, const MyInt& y);
	friend bool operator!= (const MyInt& x, const MyInt& y);

	friend ostream& operator<<(ostream& os, const MyInt& s);
	friend istream& operator>>(istream& is, MyInt& s);

public:
	MyInt(int n = 0);		// conversion from int to cstring also defualt constructor
	MyInt(const char* s);	// conversion from c-string
		

	~MyInt();			// final cleanup of dynamic space

	// DEEP COPY!!!!
	MyInt(const MyInt& s);			// copy constructor
	MyInt& operator=(const MyInt& s);	// assignment operator

	int GetSize() const;			// simple getter for size

	MyInt substring(int index, int len);	// return a substring

	void resize(MyInt & x, int newSize);



private:
	MyInt& Grow(MyInt & x);
	MyInt& CstringToInteger(MyInt & x, const char* s);
	MyInt& IntegerToCstring(MyInt & x, int n);
	MyInt resize(const MyInt& x, const MyInt& y);
	char* str;		// pointer to a dynamically managed array of chars
	int size;		// this will store the size of the string
			 //  we will ONLY allocate enough space for this
};

