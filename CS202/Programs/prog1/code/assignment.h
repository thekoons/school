// Kunio Comey
// CS202
// Program 1
// assignment.h
//
// This is the header file for the assignment class. 

#include "title.h"

#ifndef ASSIGN_H
#define ASSIGN_H

// The assignment class.
class assignment : public title
{
    public:
        // Constructors
        assignment();
        assignment(const assignment & copy);

        // Destructor
        ~assignment();


        // Member Functions
        //
        // This will read in the description for the
        // assignment.
        int read_desc();

        // This will read in the due date for the 
        // assignment.
        int read_due();

        // Display function to output the title, description,
        // and the due date.
        int display();


    protected:
        // This is a string that will hold the 
        // description for the assignment.
        str desc;

        // This  is the string to hold the due date
        // of the assignment.
        str due_date;
};

//Assignment node class.
class a_node : public assignment
{
    public:
        // Constructors
        a_node();
        a_node(const a_node & copy);

        // Destructor
        ~a_node();


        // Member Functions
        //
        // This will set the next pointer to the
        // node passed in.
        int set_next(a_node * to_set);

        // This will return the address of the next
        // node.
        a_node *& get_next();

    protected:
        // Next a_node pointer.
        a_node * next;
};

//Assignment list class.
class a_list
{
    public:
        // Constructors
        a_list();
        a_list(const a_list & copy);

        // Destructor
        ~a_list();


        // Member Functions
        //
        // This will insert a new a_node into the
        // list
        int insert();

        // This will display all of the assignments
        // in the list. Will act as a wrapper function.
        int display();

        // Function to output a menu and allow the user
        // to choose which function to invoke.
        int menu();

    protected:
        // Holds the list of assignment nodes.
        a_node * head;

    private:
        // Recursive function for display.
        int display(a_node * head);
};

#endif
