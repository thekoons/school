// Kunio Comey
// CS202
// Program 1
// assignment.cpp
//
// This is the implementation file for the assignment class.

#include "assignment.h"
using namespace std;


// ASSIGNMENT CLASS

// Default constructor
assignment::assignment() : title(false), desc(500) {}


// Copy Constructor
assignment::assignment(const assignment & copy) : title(copy),
    desc(copy.desc), due_date(copy.due_date) {}


// Destructor
assignment::~assignment() {}


// Member Functions

// This function will read in the description for assignment.
int assignment::read_desc()
{
    cout << "\nPlease enter in description for assignment: ";
    int result = desc.read();
    cout << endl;

    return result;
}


// This function will read in the due date for the assignment.
int assignment::read_due()
{
    cout << "\nPlease enter in due date for this assignment: ";
    int result = due_date.read();
    cout << endl;

    return result;
}


// This function will display the contents of the assignment.
int assignment::display()
{
    cout << endl;

    if(!title::display())
        return 0;
    
    cout << "\nDescription:\n"; 
    desc.display();
    cout << endl;

    cout << "\nDue Date: ";
    due_date.display();
    cout << endl;

    return 1;
}




// ASSIGNMENT NODE CLASS

// Default Constructor
a_node::a_node() : next(NULL) {}

// Copy Constructor
a_node::a_node(const a_node & copy) : assignment(copy), next(NULL)
{
    if(copy.next)
        next = new a_node(*copy.next);
}

// Destructor
a_node::~a_node()
{
    if(next)
        delete next;
}


// Member functions

// Setting the next pointer to the node passed in as an argument. 
int a_node::set_next(a_node * to_set)
{
    next = to_set;
    return 1;
}


// Returning the address of the next a_node.
a_node *& a_node::get_next()
{
    return next;
}




// ASSIGNMENT LIST CLASS
//
// Default Constructor
a_list::a_list() : head(NULL) {}


// Copy Constructor
a_list::a_list(const a_list & copy) 
{
    if(copy.head) 
        head = new a_node(*copy.head);
}


// Destructor
a_list::~a_list()
{
    delete head;
}


// Assignment list member functions
//
// Function to insert a new a_node
int a_list::insert()
{
    // Creating new node and reading in the 
    // information from user.
    a_node * temp = new a_node;
    temp -> read_title();
    temp -> read_desc();
    temp -> read_due();
    
    //Inserting new node into the list.
    temp->set_next(head);
    head = temp;

    return 1;
}


// Display function for the assignment list.
// This will be the wrapper function for the recursive
// function.
int a_list::display()
{
    if(!head) 
    {
        cout << "\nEmpty Assignment List\n";
        return 0;
    }
    
    cout << "\nHere are your assignments:\n";
    return display(head);
}

// Recursive function for display.
int a_list::display(a_node * head)
{
    if(!head) return 0;
    return head->display() + display(head->get_next());
}

// Menu for the assignment list.
int a_list::menu()
{    
    int choice;

    // Do while loop for the menu so we can do multiple inputs.
    do
    {
        cout << "\n1 --- Insert new assignment."
             << "\n2 --- Display assignments."
             << "\n0 --- Quit."
             << "\nWhat would you like to do? (input integer): ";
        
        cin >> choice; cin.ignore(100,'\n'); cin.clear();

        if(choice == 1) 
            insert();

        else if(choice == 2) 
            display();

        else if(!choice)
            cout <<"\nQuitting...";
        else
            cout << "\nInvalid integer input.\n";
    
    } while(choice);

    return 1;
}
