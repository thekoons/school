//Kunio Comey
//CS202
//Program 3
//main.cpp

#include "str.h"
#include "info.h"
#include "table.h"

using namespace std;

//Main function for the program.
int main()
{
    //OUTPUT MESSAGE FOR USER.
    cout << "\nWELCOME TO THE INFORMATION OVERLOAD PROGRAM.\n";

    cout << "\nTesting info.";
    // Testing out info overloaded functions.
    //
    
    info * ptr = new website;
    cout << *ptr;
    ptr->read();
    cout << *ptr;

    /* Testing string class. */
    /*
    cout << "\nEnter a";
    str a; cin >> a; cin.ignore(100,'\n');
    cout << "\nEnter b";
    str b; cin >> b; cin.ignore(100,'\n');
    cout << endl;
    str match = a;
    
    if(a < b) 
        cout << "\n< works";

    if(a <= match && a <= b) 
        cout << "\n<= works";

    if(b > a) 
        cout << "\n> works.";

    if(match >= a && b >= a) 
        cout << "\n>= works.";

    if(match == a) 
        cout << "\n== works.";

    if(a != b) 
        cout << "\n!= works.";

    cout << endl;
    */

    return 1;
}
