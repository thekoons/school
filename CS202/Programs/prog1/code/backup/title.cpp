// Kunio Comey
// CS202
// Program 1
// title.cpp
//
// This is the implementation file for the title, message, and 
// message node classes.


#include "title.h"
using namespace std;

//TITLE CLASS

//Constructor
title::title() : isname(NULL) {}


//Constructor with a bool passed in.
title::title(const bool if_name) : isname(if_name) {}


//Copy Constructor
title::title(const title & copy) : str(copy), isname(copy.isname) {}


//Member Functions of class title.
int title::read_title() 
{
    //Determining which output based on the isname flag.
    if(isname)  
        cout << "\nPlease enter you name: ";
    //Else for when the isname flag is false.
    else        
        cout << "\nPlease enter title: ";

    //Catching the result of the read function.
    int result = read();
    cout << "\n";

    //Returning the statement from the read function online.
    return result; 
}


//Member function to output the title to the console.
int title::display()
{
    //Checking if it is a name or not.
    if(isname) cout << "\nName: ";
    else cout << "\nTitle: ";

    int result = str::display();

    return result;
}

 

//MESSAGE CLASS

//Constructor
//
//  This will call the constructor with the true passed in
//  to indicate that the title is a name.
//
//  Mess has a 500 passed in to make the str variable be able
//  to hold a size of 500.
//
message::message() : title(true), mess(500) {}


//Copy Constructor
message::message(const message & copy) : title(copy), mess(copy.mess) {}



//Member functions
int message::read_message()
{
    cout << "\nPlease enter in your message: ";
    int result = mess.read();
    cout << endl;

    return result;
}

//Displays both the message and the name
int message::display()
{
    //These variables hold the results of each
    //display function.
    int r1 = title::display();
    cout << endl;

    int r2 = mess.display();
    cout << endl << endl;

    //If either of the display functions return a 0,
    //return a 0 from this function.
    if(!r1 || !r2) return 0;
    return 1;
}




//MESSAGE NODE CLASS
//
//This is the vessel for allowing messages to be in a
//message list.

//Constructor
m_node::m_node() : next(NULL) {}

//Copy Constructor
m_node::m_node(const m_node & copy) : message(copy), next(NULL)
{
    if(copy.next)
        next = new m_node(*copy.next);
}

//Destructor
m_node::~m_node()
{
    if(next)
        delete next;
}

//Connecting a node to next.
int m_node::set_next(m_node * tmp)
{
    next = tmp;
    return 1;
}

//Getting the address of the next message in the list.
m_node *& m_node::get_next()    
{
    return next;
}




// MESSAGE LIST CLASS

// Default constructor
m_list::m_list() : head(NULL) {}


// Copy Constructor
m_list::m_list(const m_list & copy) : head(NULL)
{
    if(!copy.head) return;
    head = new m_node(*copy.head);
}

//Destructor
m_list::~m_list()
{
   if(head) delete head;
}


// Member Functions
//
// Function to insert a new message into the list.
int m_list::insert()
{
    m_node * temp = new m_node();

    temp->read_title();
    temp->read_message();

    /*
    if(!head)
    {
        head = temp;
        return 1;
    }
    */

    //Setting the temp's next to the original head of the
    //list.
    temp->set_next(head); 

    //Setting head to the temp.
    head = temp;

    return 1;
}


// Function to display the whole list. This will be the wrapper function.
int m_list::display()
{
    if(!head) 
    {
        cout << "Empty Message List.";
        return 0;
    }

    // Will display all of the messages and count the
    // number of messages in the list.
    cout << "\nHere is are your messages: \n";
    int count = display(head);
    cout << endl << count << " messages.\n";

    // Returning the number of messages if it is needed.
    return count;
}


//Recursive function for the display.
int m_list::display(m_node * head)
{
    if(!head) return 0;

    head->display();
    return 1 + display(head->get_next());
}


// Menu function for choosing which functions to invoke from
// the client.
int m_list::menu()
{
    int choice;

    do
    {
        cout << "\n1 --- Insert new message."
             << "\n2 --- Display messages."
             << "\n0 --- Quit."
             << "\nWhat would you like to do? (input integer): ";
        
        cin >> choice; cin.ignore(100,'\n'); cin.clear();

        if(choice == 1) 
            insert();

        else if(choice == 2) 
            display();

        else if(!choice)
            cout << "\nQuitting...";

        else
            cout << "\nInvalid integer input.\n";
    
    } while(choice);


    return 1;
}

