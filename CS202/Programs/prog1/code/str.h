// Kunio Comey
// CS202
// Program 1
// str.h
//
// This is the header file for the str (string) class.

#ifndef STR_H
#define STR_H

#include <iostream>
#include <cstring>
#include <cctype>



// This is the str class to make it easier to 
// use character arrays.
class str
{
    public:
        // Default constructor
        str();

        // Constructor with an integer passed in
        // to create a str of a larger size than
        // 100.
        str(const int maximum);

        // Copy constructor
        str(const str & copy);

        // Destructor
        ~str();

        // Functions
        //
        // Reads in a character array.
        int read();

        // Deallocating the memory in the character array.
        int clear();

        // Displaying the contents to the client.
        int display();

        // Filling the str that's passed in with the contents
        // the current str.
        int fill(str & to_copy);

        // Used to copy the contents of one str to another.
        int copy(const str & source);

        // Compare function to return the strcmp value.
        int compare(const str & cmp);

    protected:
        //Variable to hold the character array
        char * a_str;

        // Hold the length of the str.
        int length;

        // For making a maximum when you need to read in
        // a bigger str.
        int max;
};

#endif
