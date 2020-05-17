//Kunio Comey
//CS202
//Program 3
//table.cpp

#include "table.h"
using namespace std;

//DATA CLASS

//Default constructor
data::data(void) : ptr(NULL) {}

//Copy constructor
data::data(const data & copy) : ptr(NULL) 
{
    //Base case.
    if(!copy.ptr) return;
    info * source = copy.ptr;

    //Checking each derived type to determine which type of
    //object to copy over.
    zoom_id * test = dynamic_cast<zoom_id *>(*source);
    if(test) ptr = new zoom_id(*source);
    else
    {
        website * test = dynamic_cast<website *>(*source);
        if(test) ptr = new website(*source);
        else
        {
            app * test = dynamic_cast<app *>(*source);
            if(test) ptr = new app(*source);
        }
    }
}

//Destructor
data::~data(void)
{
    if(!ptr) return;
    delete ptr;
    ptr = NULL;
}

//Read function to determine which kind of item we are creating.
void data::read()
{
    //If there is memory in ptr, deallocate it to prevent a memory leak.
    if(ptr) 
    {
        delete ptr;
        ptr = NULL;
    }
    
    int user_choice = 0;
    char again = '\0';

    //Menu for the user to read in the information.
    cout << "\nDATA MENU:"
         << "\n1\t---\tSave Zoom ID"
         << "\n2\t---\tSave Website"
         << "\n3\t---\tSave Application"
         << "\nPlease enter an integer value (1-3): ";
    cin >> user_choice; cin.ignore(100,'\n'); cin.clear();
    
    //If the user's choice is out of bounds, call the function
    //again.
    if(user_choice > 3 || user_choice < 1)
    {
        cout << "\nInvalid option selected. Please try again.";
        read();
        return;
    }

    //Switch statement to determine which derived object we are
    //creating.
    switch(user_choice)
    {
        case 1: //Making a zoom id
           ptr = new zoom_id;
           break;

        case 2: //Making a website
           ptr = new website;
           break;

        case 3: //Making an application
           ptr = new application;
           break;

        default:
           cout << "\nInvalid input.\n";
           break;
    }

    //Just checking in case the default statement somehow go triggered
    //before calling the read function.
    if(ptr) ptr->read();
}

//Function to compare the name value to the data passed in as an argument.
int data::compare(const data & to_cmp) const
{
    //If there is no data, get the heck out of dodge.
    //ideally this shouldn't happen with the precautions
    //used in the tree structure.
    if(!this->ptr || !to_cmp->ptr) 
    {
        cout << "\nNO POINTERS HERE.\n";
        return 0;
    }

    //Returning the string compare value of data's name.
    return ptr->compare(to_cmp->ptr); 
}

//Display function for data.
void data::display(void) const
{
    if(!ptr) return;
    ptr->display();
}


