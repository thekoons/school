// Kunio Comey
// CS202
// Program 3
// str.cpp
//
// This is the implementation file for the str (string) class.


#include "str.h" 
using namespace std;

// Default constructor.
str::str() : a_str(NULL), 
    length(0), 
    max(100) {}


// Constructor to set the maximum value of to an integer passed in.
str::str(int maximum) : a_str(NULL), 
    length(0), 
    max(maximum) {}

// Constructor with a character array passed in.
str::str(char * array) : a_str(array), 
    length(strlen(array)), 
    max(100) {}

// Copy Constructor
str::str(const str & copy) : max(copy.max)
{
    length = copy.length;
    a_str = new char[length + 1];
    strcpy(a_str, copy.a_str);
}

// Destructor
str::~str()
{
    if(a_str)
        delete [] a_str;
}


// Public Member Functions
//
// Function to read in a str. 
int str::read()
{
    // Deallocating the memory for the string.
    clear();

    // Reading into a temporary character array.
    char temp[max];
    cin.get(temp, max, '\n'); cin.ignore(100,'\n');
    length = strlen(temp);

    // Allocating the memory for the character array.
    a_str = new char[length + 1];
    strcpy(a_str, temp);

    return 1;
}


// Function to deallocate the memory for str so that
// you can read in a new character array.
int str::clear()
{
    if(!a_str) return 0;
    delete [] a_str;
    a_str = NULL;
    length = 0;

    return 1;
}


// Display function to display the str.
int str::display()
{
    if(!a_str) return 0;
    cout << a_str;    
    return 1;
}

// Copies the contents over to another str that
// was passed in.
int str::fill(str & to_copy)
{
    if(!a_str) return 0;
    return to_copy.copy(*this);
}


// This copy function will the contents from the
// str passed in to the str member variable.
int str::copy(const str & source)
{
    // Return 0 if the string being passed in to copy
    // from is null.
    if(!source.a_str) return 0;

    //Clearing the current string value.
    clear();

    // Copying the length and the contents of the source
    // string to the current class's string.
    length = source.length;
    a_str = new char[length + 1];
    strcpy(a_str, source.a_str);
    
    return 1;
}  


// This is the compare function to compare two different
// strings. Will return a 0 if the compare shows no match
// and will return a 1 if there is a match.
int str::compare(const str & cmp)
{
    return strcmp(a_str, cmp.a_str);
}

//Overloading the equals operator
str & str::operator=(const str & copy)
{
    if(this == &copy)
        return *this;

    if(a_str)
        delete [] a_str;

    length = copy.length;
    a_str = new char[length + 1];
    strcpy(a_str, copy.a_str);
    return *this;
}

//Overloading equals operator when an character array is 
//passed.
str & str::operator = (const char * array)
{
    if(a_str)
        delete [] a_str;

    length = strlen(array);
    a_str = new char[length + 1];
    strcpy(a_str, array);
    return *this;
} 

//Compound plus equal operator overload.
str & str::operator += (const str & to_add)
{
    length += to_add.length;
    char * temp = new char[length + 1];
    strcpy(temp, a_str);
    strcat(temp, to_add.a_str);

    if(a_str)
        delete [] a_str;

    a_str = temp;
    return *this;
}

//Compound plus equal operator overloaded with a 
//character array passed in.
str & str::operator += (const char * to_add)
{
    length += strlen(to_add);
    char * temp = new char[length + 1];
    strcpy(temp, a_str);
    strcat(temp, to_add);

    if(a_str)
        delete [] a_str;

    a_str = temp;
    return *this;
}

//Overloaded plus operator with s1 = str and s2 = char *.
str operator + (const str & s1, const char * s2)
{
    char * temp = new char[s1.length + strlen(s2) + 1];
    strcpy(temp, s1.a_str);
    strcat(temp, s2);
    return str(temp);
}

//Plus operator with s1 = char * and s2 = str.
str operator + (const char * s1, const str & s2)
{
    char * temp = new char[strlen(s1) + s2.length + 1];
    strcpy(temp, s1);
    strcat(temp, s2.a_str);
    return str(temp);
}

//Plus operator with s1 = str and s2 = str.
str operator + (const str & s1, const str & s2)
{
    char * temp = new char[s1.length + s2.length + 1];
    strcpy(temp, s1.a_str);
    strcat(temp, s2.a_str);
    return str(temp);
}

//Overloading the extraction operator.
istream & operator >> (istream & in, str & s)
{
    char temp[s.max];
    in.get(temp, s.max, '\n');
    s = temp;
    return in;
}

//Overloading the insertion operator.
ostream & operator << (ostream & out, const str & s)
{
    out << s.a_str;
    return out;
}

//Less than operator overload.
bool operator < (const str & s1, const char * lit)
{
    return (strcmp(s1.a_str, lit) < 0); 
}

bool operator < (const str & s1, const str & s2)
{
    return (strcmp(s1.a_str, s2.a_str) < 0);
}

bool operator < (const char * lit, const str & s2)
{
    return (strcmp(lit, s2.a_str) < 0);
}

//Greater than operator overload.
bool operator > (const str & s1, const char * lit)
{
    return lit < s1;
}

bool operator > (const char * lit, const str & s2)
{
    return s2 < lit;
}

bool operator > (const str & s1, const str & s2)
{
    return s2 < s1;
}

//Less than or equal to operator.
bool operator <= (const str & s1, const char * lit)
{
    return (strcmp(s1.a_str, lit) <= 0);
}

bool operator <= (const char * lit, const str & s2)
{
    return (strcmp(lit, s2.a_str) <= 0);
}

bool operator <= (const str & s1, const str & s2)
{
    return (strcmp(s1.a_str, s2.a_str) <= 0);
}

//Greater than or equal to operator.
bool operator >= (const str & s1, const char * lit)
{
    return lit <= s1;
}

bool operator >= (const char * lit, const str & s2)
{
    return s2 <= lit;
}

bool operator >= (const str & s1, const str & s2)
{
    return s2 <= s1;
}

//Equality operator.
bool operator == (const str & s1, const char * lit)
{
    return !strcmp(s1.a_str, lit);
}

bool operator == (const char * lit, const str & s2)
{
    return !strcmp(lit, s2.a_str);
}

bool operator == (const str & s1, const str & s2)
{
    return !strcmp(s1.a_str, s2.a_str);
}

//Inequality operator
bool operator != (const str & s1, const char * lit)
{
    return strcmp(s1.a_str, lit);
}

bool operator != (const char * lit, const str & s2)
{
    return s2 != lit;
}

bool operator != (const str & s1, const str & s2)
{
    return strcmp(s1.a_str, s2.a_str);
}
