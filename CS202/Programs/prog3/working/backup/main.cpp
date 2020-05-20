//Kunio Comey
//CS202
//Program 3
//main.cpp

#include "str.h"
#include "info.h"
#include "table.h"

using namespace std;

int test_info_ops();

//Main function for the program.
int main()
{
    int user_choice;
    tree my_tree;

    //OUTPUT MESSAGE FOR USER.
    cout << "\nWELCOME TO THE INFORMATION OVERLOAD PROGRAM.\n";
    cout << "\nHow to test: For name input a single character when prompted. The tree will"
         << "\nbe organized in alphabetical order.";

    do
    {
        cout << "\nHere is the menu: "
             << "\n1\t---\tTest Info Operations"
             << "\n2\t---\tDisplay Tree"
             << "\n3\t---\tInsert Tree"
             << "\n4\t---\tSearch Tree"
             << "\n5\t---\tRemove node from tree"
             << "\n0\t---\tQuit";
        cout << "\nPlease enter your choice here (integer value): ";
        cin >> user_choice; cin.ignore(100,'\n'); cin.clear();

        switch(user_choice)
        {
            case 1: 
                if(test_info_ops())
                    cout << "\nInformation operations work.";
                break;

            case 2:
                my_tree.display();
                break;

            case 3:
                my_tree.insert();
                break;

            case 4:
                my_tree.search();
                break;

            case 5:
                my_tree.remove();
                break;

            case 0:
                cout << "\nThank you for using this program.\n";
                break;
        }

    } while (user_choice);

    return 1;
}

//Function to test the overloaded functions of info.
int test_info_ops()
{
    // Testing out info overloaded functions.
    cout << "\nTesting info base class overloaded objects.";
    
    //Creating new derived objects with a base pointer.
    info * ptr1 = new website;
    info * ptr2 = new app;
    info * copy = new zoom_id;

    //Reading in for ptr1.
    cout << "\nPlease enter website name: ";
    cin >> *ptr1;
    cout << *ptr1 << endl; 
    
    //Reading in for ptr2.
    cout << "\nPlease enter app name: "; 
    cin >> *ptr2;

    //Testing plus equal to operator:
    *ptr2 += *ptr1;
    cout << "\nHere is app's name combined with website name: "
         << *ptr2 << endl;

    //Testing plus operator:
    *ptr2 = *ptr2 + *ptr1;
    cout << "\nHere's a repeat of the above operation using the plus operator: "
         << *ptr2 << endl;

    //Making a copy. Testing assignment operator.
    *copy = *ptr1;
    cout << "\nCopy's contents: " << *copy << endl;

    //Should perform else clause.
    if(*ptr1 < *copy) cout << "Copy is greater than ptr1\n";
    else
        cout << "Less than operator works\n";

    //Should perform else clause.
    if(*ptr1 > *copy) cout << "Copy is less than ptr1\n"; 
    else
        cout << "Greater than operator works\n";

    //These 3 statements should execute
    if(*ptr1 <= *copy) cout << "Copy is greater than or equal to ptr1\n";
    if(*ptr1 >= *copy) cout << "Copy is less than or equal to ptr1\n";
    if(*ptr1 == *copy) cout << "Copy is equal to copy\n";

    //Should perform else clause.
    if(*ptr1 != *copy) cout << "Copy is not equal to copy\n";
    else
        cout << "Not equals operator works\n";

    //Deallocating the memory.
    delete ptr1; delete ptr2; delete copy;

    return 1;
}

