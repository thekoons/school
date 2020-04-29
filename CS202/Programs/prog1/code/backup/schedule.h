// Kunio Comey
// CS202
// Program 1
// schedule.h
//
// This is the header file for the schedule which
// will hold an array of linear linked lists.

#include "assignment.h"

#ifndef SCHED_H
#define SCHED_H

// Event class to be put into the schedule
class event : public title
{
    public:
        // Constructors
        event();
        event(const event & copy);

        // Destructor
        ~event();

        // Member functions
        //
        // Function to read in the date
        int read_time();

        // Function to read in the description
        int read_desc();

        // This will display the contents of this.
        int display();
        
    protected:
        // String to hold the date of the event.
        str time;

        // String to hold the description of the event.
        str desc;

};


// Event node class so we can make a data structure of this.
class e_node : public event
{
    public:
        // Constructors
        e_node();
        e_node(const e_node & copy);

        // Destructors
        ~e_node();

        // Member functions
        //
        // Function to set the next pointer
        int set_next(e_node * temp);

        // Function to return the address of the next.
        e_node *& get_next();

    protected:
        e_node * next;
};


// Schedule class that will act as the data structure
// for events.
class schedule
{
    public:
        // Constructors
        schedule();
        schedule(const schedule & copy);

        // Destructor
        ~schedule();

        // Member functions
        //
        // Function to insert a new event into the schedule
        int insert();

        // Wrapper function for the display function.
        int display();

        // Menu function so the user can choose to insert or
        // display.
        int menu();

    protected:
        e_node ** table;
        int size;

        // Used for initializing the table.
        int initialize(e_node ** ptr, int & count);
        
        // Used for copy constructor to copy a table.
        int copy_table(const schedule & copy, int & count);

        // Used for the destructor to recursively free all memory.
        int destroy(e_node ** ptr, int & count);

        // Recursive display function for the element part of the
        // array.
        int display(e_node ** ptr, int & count);

        // Recursive display function for the linear linked list
        int display(e_node * head);
};

#endif
