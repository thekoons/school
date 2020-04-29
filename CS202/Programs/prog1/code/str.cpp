// Kunio Comey
// CS202
// Program 1
// str.cpp
//
// This is the implementation file for the str (string) class.


#include "str.h" 
using namespace std;

// Default constructor.
str::str() : a_str(NULL), length(0), max(100) {}


// Constructor to set the maximum value of to an integer passed in.
str::str(int maximum) : a_str(NULL), length(0), max(maximum) {}


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

   
