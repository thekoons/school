// Kunio Comey
// CS202
// Program 1
// schedule.cpp
//
// This is the implementation file for the schedule.

#include "schedule.h"
using namespace std;


// EVENT CLASS

// Not necessary since the default constructors for str
// already put in null values.
event::event() : title(false) {}

// Copy Constructor
event::event(const event & copy) : title(copy),
    desc(copy.desc) {}

// Destructor (unneccessary since date and desc deallocate
// memory themselves.
event::~event() {}


// Member functions
//
// Function to read in the date for the event.
int event::read_time()
{
    cout << "\nEnter in the time for this event: ";
    int result = time.read(); 
    cout << endl;

    return result;
}


// Function to read in the descrtiption for the event.
int event::read_desc()
{
    cout << "\nPlease enter in the description for this event: ";
    int result = desc.read();
    cout << endl;

    return result;
}


// Function to display the description and the date.
int event::display()
{
    title::display();

    cout << "\nTime: ";
    time.display();

    cout << "\nDescription: ";
    desc.display();

    cout << endl;

    return 1;
}




// EVENT NODE CLASS

// Default constructor
e_node::e_node() : next(NULL) {}


// Copy Constructor
e_node::e_node(const e_node & copy) : event(copy), next(NULL)
{
    if(copy.next) 
        next = new e_node(*copy.next); 
}


// Destructor
e_node::~e_node()
{
    if(next)
        delete next;
}


// Member functions
//
// Set next function
int e_node::set_next(e_node * temp)
{
    next = temp;
    return 1;
}


// Get next function
e_node *& e_node::get_next()
{
    return next;
}




// SCHEDULE CLASS

// Default constructor
schedule::schedule() : size(30)
{
    // Allocating memory for the array of e_node pointers
    table = new e_node * [size];

    // Initializing all of the elements in the e_node pointer array.
    e_node ** ptr = table;
    int count = 0;

    initialize(ptr, count); 
}


// Recursive initialization function.
int schedule::initialize(e_node ** ptr, int & count)
{
    if(count == size) return 1;
    *ptr = NULL;
    return initialize(++ptr, ++count);
}


// Copy Constructor
schedule::schedule(const schedule & copy) : size(copy.size)
{
    //Allocating memory for the array of e_node pointers.
    table = new e_node * [size];

    //Making temporaries to use pointer arithmetic to go through
    //each array.
    //e_node * source = copy.table;

    int count = 0;
   
    copy_table(copy, count);
}


// Recursive copy function
int schedule::copy_table(const schedule & copy, int & count)
{
    if(count == size) return 1;

    if(!copy.table[count])
        table[count] = NULL;
    else
        table[count] = new e_node(*copy.table[count]);

    return copy_table(copy, ++count);

    /*
    if(!*source)
        *ptr = NULL;
    else
        *ptr = new e_node(**source);

    return copy(ptr, source, ++count);
    */
} 


// Destructor
schedule::~schedule()
{
    // Making temporary pointer for deleting all nodes.
    e_node ** ptr = table;
    // Holding a count so we don't go beyond the bounds of the
    // array.
    int count = 0;

    // Calling the recursive destroy function for the e_nodes.
    destroy(ptr, count);
    
    // Deallocating the array itself.
    delete [] table;
}


// Recursive function to destroy the e_nodes in each element of the
// array.
int schedule::destroy(e_node ** ptr, int & count)
{
    if(count == size) return 1;

    if(*ptr) delete *ptr;
    return destroy(++ptr, ++count); 
}


// Insert function
int schedule::insert()
{
    // This variable will hold the day of the month
    // to insert a new event into.
    int day;
    cout << "\nEnter in day of the month you wish to add to\n"
         << "(this should be an integer value between 1 and 30: ";
    cin >> day; cin.ignore(100,'\n'); cin.clear();

    // If the wrong input is made, recall this insert function.
    if(day < 1 || day > 30) 
    {
        cout <<"\nInvalid integer input.\n";
        return insert(); 
    }

    // Filling this node to prep for insert.
    cout << "\nNow creating event...\n";
    e_node * temp = new e_node;
    temp->read_title();
    temp->read_time();
    temp->read_desc();

    // Set the pointer to the element in the array that the user
    // chose to insert a new event into.
    e_node ** ptr = &table[day - 1];
    
    // Setting temps next to the original head of the list.
    temp->set_next(*ptr);
    *ptr = temp;

    return 1;
}


// Wrapper function for the display function.
int schedule::display()
{
    int count = 0;
    e_node ** ptr = table;

    return display(ptr, count);
}


// Recursive display function for the elements in the array.
int schedule::display(e_node ** ptr, int & count)
{
    if(count == size) return 1;
    
    cout << "\nDay " << count + 1 << ":\n";

    if(*ptr)
        display(*ptr);

    return display(++ptr, ++count);
}


// Recursive display function for the linear linked list.
int schedule::display(e_node * head)
{
    if(!head) return 1;

    head->display();
    return display(head->get_next());
}


// Menu function so user can choose to insert or display.
int schedule::menu()
{
    int choice;

    // Do while loop for the menu so we can do multiple inputs.
    do
    {
        cout << "\n1 --- Insert new event."
             << "\n2 --- Display events."
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

