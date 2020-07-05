#include <cstring>
#include "myint.h"


/*
   char* str;		// pointer to a dynamically managed array of chars
   int size;		// this will store the size of the string
			//  allocation will be size+1 at all times
			//  and we will store internally as a c-string
*/

// friend function definitions
// ***************************************************************CONCATINATION OF TWO CSTRINGS OF INTEGERS*************************************************************************************************************************
MyInt operator+ (const MyInt& x, const MyInt& y) {
	
	int i, j;
	//we need to create a new string herre to handle the ombination of both strings
	MyInt Temp;
	Temp.size = strlen(x.str) + strlen(y.str);
		Temp.str = new char[Temp.size+1];
		//we need to copy string 1 into temp
		for (i = 0; x.str[i] != '\0'; i++)
			Temp.str[i] = x.str[i];

		cout <<"x.str[i] is " << x.str[i] << endl;
		Temp.str[i] = x.str[i]; //copy null terminator
		cout << "The new Temp str is " << Temp.str << endl;
	//This starts at the end of the first string and prints the rest of the second string until it reaches the null character
		for (i = strlen(x.str), j = 0; y.str[j] != '\0'; i++, j++)
			Temp.str[i] = y.str[j];

		//This has to be Temp.str[i-1] to not sucsefully add null character to the end**********************************************************************
		Temp.str[i-1] = y.str[j];	// copy final '\0' from s2 into end of s1
		//***************************************************************************************************************************************************

		//****************************NICE
		return Temp;
	
	//MyInt Temp = Temp.resize(x, y);

	//tests assignemt operator
	 //Temp = Temp.resize(x.str, y.str);
	//cout << "The size is " << Temp.size << endl;
	
	return Temp;
}

//*******************************************************************************************************************************************************************************************************************************************


//*********************************************************************************************CONVERSION FUNCTIONS WE WERE GIVEN FROM CHAR TO INTS AND VICE VERSA****************************************************************************
int C2I(char c)
// converts character into integer (returns -1 for error)
{
	if (c < '0' || c > '9')	return -1;	// error
	return (c - '0');				// success
}

char I2C(int x)
// converts single digit integer into character (returns '\0' for error)
{
	if (x < 0 || x > 9)		return '\0';	// error
	return (static_cast<char>(x) + '0'); 	// success
}
//**********************************************************************************************************************************************************************************************************************************************

//*****************************************************************************************OVERLOADED EXTRACTION OPERATOR***********************************************************************************************************************
ostream& operator<<(ostream& os, const MyInt& s)
{
	os << s.str;		// print the c-string using operator<<
 /*
	for (int i = 0 ; i < s.size; i++)
		os << s.str[i];
 */

	return os;
}

//***********************************************************************************************************************************************************************************************************************************************
// member function definitions


//******************************************************************************************DEFUALT CONSTRUCTOR ALSO INITILIZE WITH AND INTEGER**************************************************************************************************
MyInt::MyInt(int n)
// creates an empty string
{

	
	int counter = 0; //This will descide how large of an array we should grow to 
	if (n <= 0) {
		cout << "running defualt constructor" << endl;
		cout << "n is less than zero" << endl;
		size = 0;
		str = new char[1];
		str[0] = '\0';
		return;
	}

	cout <<"Running constructor for integer..." << endl;

	int number = n;
	int tmp = 0;
	while (number > 0) {
		tmp = number % 10;
		counter++;
		number /= 10;
	}
	
	size = counter;
	cout << "Counter is " << counter << endl;
	str = new char[size + 1];
	cout << "str size is " << size << endl;

	tmp = 0;
	int i = 0;
	while (n > 0) {
		tmp = n % 10;
		cout << "Next character is " << I2C(tmp) << endl;
		str[i] = I2C(tmp);
		i++;
		n /= 10;
	}
	


}
//********************************************************************************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************************************************INTEGER TO CSTRING***(PRIVATE)
MyInt& MyInt::IntegerToCstring(MyInt & x, int n)
//takes a object by reference and an integer in ints parameters and transforms it into a cstring that will be assigned to an object.
//That object will then be returned.
//This object will most likley be copied to another object using assignment operator
{
	
	int counter = 0;
	if(n <= 0){
		x.size = 0;
		x.str = new char[1];
		x.str[0] = '\0';
		return x;
	}
	int number = n;
	int tmp = 0;
	while(number > 0){
		tmp = number % 10;
		counter++;
		number /=10;
	}
	x.size = counter;
	cout << "counter is " << counter << endl;
	x.str = new char[size + 1];
	cout << "str size is " << size << endl;

	tmp = 0;
	int i = 0;
	while (n > 0){
		tmp = n % 10;
		cout <<"Next character is " << I2C(tmp) << endl;
		str[i] = I2C(tmp);
		i++;
		n /=10;
	}

	return x;



}
//*******************************************************************************************************************************************************************************************************************************************

//**********************************************************************************************************************************************************************************************************************CSTRING TO INTEGER(PRIVATE)
MyInt& MyInt::CstringToInteger(MyInt & x, const char * s){



return x;

}


//******************************************************************************************************************************************************************************************************************************************************

//**********************************************************************************************COPY CONSTRUCTOR******************************************************************************************************************************
MyInt::MyInt(const MyInt& D)
// copy constructor.  Initialize object as a copy of D
{
	cout << "running copy constructor" << endl;
	size = D.size;
	size = D.size;

	// allocate new array of Entry objects
	str = new char[size+1];

	// copy the list over from D
	for (int i = 0; i < size; i++)
		str[i] = D.str[i];
}
//************************************************************************************************************************************************************************************************************************************************



//*******************************************************************************************ASSIGNMENT OPERATOR**********************************************************************************************************************************
MyInt& MyInt::operator= (const MyInt& D)
// assignment operator (a member function)
// does a similar task to that of the copy constructor
//  but is not a new object, so must delete any existing allocation
//  and must return the assigned value (i.e. this object, *this)
{

	cout <<"Running assignment operator" << endl;
	if (this != &D)		// only make the copy if the original is
	{				//  not this same object

	   // first, delete the existing array
		delete[] str;

		// now do the copy.  Same way we did copy constructor
		size = D.size;
		str = new char[size+1];
		for (int i = 0; i < size; i++) {
			cout << "Temp: " << D.str[i] << endl;
			str[i] = D.str[i];
		}
	}

	return *this;		// return this object
}

//******************************************************************************************************************************************************************************************************************************************************


//*****************************************************************************************************CONSTRUCTOR USING CSTRING************************************************************************************************************************

MyInt::MyInt(const char* s)
// inits this string to have the data from the parameter c-string
{
	cout << "running constructor using cstring" << endl;
	size = strlen(s);	// figure out the size of the incoming c-string
	str = new char[size + 1];
	/*
	   for (int i = 0; i < size; i++)
		  str[i] = s[i];
	*/

	strcpy(str, s);	// this now works because we allocate to size+1
}
//*********************************************************************************************************************************************************************************************************************************************************

//******************************************************************************************************GETTER FUNCTION FOR SIZE***************************************************************************************************************************
int MyInt::GetSize() const
{
	return size;
}
//*********************************************************************************************************************************************************************************************************************************************************

//*****************************************************************************************************************************************************************************************************************************************DECONSTRUCTOR
MyInt::~MyInt()
// clean up
{
	delete[] str;
}
//******************************************************************************************************************************************************************************************************************************************


//***********************************************************************************************************************************************************************************************************************************COMPARISON OPERATORS
bool operator< (const MyInt& x, const MyInt& y) {

	//if the x size greater return false
	if (x.size > y.size)
		return false;

	//if x size less than return true
	if (x.size < y.size)
		return true;

	//then they are the same siize
	for (int i = 0; i < x.size; i++) {

		//the first digit where x is less than then retrun true
		if (C2I(x.str[i]) < C2I(y.str[i]))
			return true;

		//if they are equal check next number
		if (C2I(x.str[i]) == C2I(y.str[i]))
			continue;

		//return false otherwise
		return false;
	}

	return true;
}

bool operator<= (const MyInt& x, const MyInt& y) {
	if (x < y || x == y)
		return true;

	return false;
}

bool operator==(const MyInt& x, const MyInt& y) {
	//same size
	if (x.size == y.size) {

		//if a number is different then return false
		for (int i = 0; i < x.size; i++) {
			if (x.str != y.str)
				return false;
		}

		return true;
	}
	//different size they are not equal
	return false;
}

bool operator>= (const MyInt& x, const MyInt& y) {

	if (!(x < y) || x == y)
		return true;

	return false;
}

bool operator> (const MyInt& x, const MyInt& y) {
	if (!(x < y) || !(x == y))
		return true;

	return false;
}

void MyInt::resize(MyInt& x,int newSize) {
	 x.size = newSize;			// Determine a new size.
	char* newList = new char[size+1];		// Allocate a new array.

	for (int i = 0; i < size; i++)	// Copy each entry into
		newList[i] = str[i];		// the new array.

	delete[] str;			// Remove the old array
	str = newList;			// Point old name to new array.

}

MyInt MyInt::resize(const MyInt & x, const MyInt & y) {
	int i, j;
	//we need to create a new string herre to handle the ombination of both strings
	MyInt Temp;
	Temp.size = strlen(x.str) + strlen(y.str);
	Temp.str = new char[Temp.size + 1];
	//we need to copy string 1 into temp
	for (i = 0; x.str[i] != '\0'; i++)
		Temp.str[i] = x.str[i];

	Temp.str[i] = x.str[i]; //copy null terminator
	cout << "The new Temp str is " << Temp << endl;
	//This starts at the end of the first string and prints the rest of the second string until it reaches the null character
	for (i = strlen(Temp.str), j = 0; y.str[j] != '\0'; i++, j++)
		Temp.str[i] = y.str[j];
	cout << "The new Temp str is " << Temp << endl;
	Temp.str[i] = y.str[j];	// copy final '\0' from s2 into end of s1

	return Temp;
}
//*****************************************************************************************************************************************************************************************************************************************************


MyInt& MyInt::Grow(MyInt& x)
// Double the size of the directory's entry list
// by creating a new, larger array of entries
// and changing the directory's pointer to refer to
// this new array.
{
	x.size = x.size +1;			// Determine a new size.
	char* newStr = new char[size+1];		// Allocate a new array.

	for (int i = 0; i < size; i++)	// Copy each entry into
		newStr[i] = x.str[i];		// the new array.

	delete[] x.str;			// Remove the old array
	x.str = newStr;			// Point old name to new array.
}

