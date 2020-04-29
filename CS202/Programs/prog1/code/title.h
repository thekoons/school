//File: title.h
//Author: Kunio Comey
//Class: CS202
//Description: This is the header file for the title, message, message
//node, and message list class.

#include "str.h"

#ifndef TITLE_H
#define TITLE_H

// This will be a str variable tweaked for a title or
// a name.
class title : public str
{
    public:
        //Class constructors.
        title();
        title(const bool if_name);
        title(const title & copy);

        //Member functions affecting parent
        //str.
        int read_title();
        int display();

    protected:
        //To determine if this is a name. If it's true,
        //it is a name. If it's false, then it is a title.
        bool isname;
};

#endif



#ifndef MESSAGE_H
#define MESSAGE_H

// This class will inherit the title for holding the
// name of the recipient.
class message : public title
{
    public:
        //Message constructors.
        message();
        message(const message & copy);

        //Member functions
        int read_message();
        int display();

    protected:
        //Str variable to hold the message itself.
        str mess;
};


// This class will inherit from message and will be
// a node for a list.
class m_node : public message
{
    public:
        //Message node constructors
        m_node();
        m_node(const m_node & copy);
        ~m_node();

        //Member functions
        int set_next(m_node * copy);
        m_node *& get_next();

    protected:
        m_node * next;
};


// Message List Class
class m_list
{
    public:
        //Constructors
        m_list();
        m_list(const m_list & copy);

        // Destructor
        ~m_list();

        // Member functions
        //
        // This will insert a new message into the list.
        int insert();

        // This will display the contents of the list. 
        int display();
        
        // This will be a menu for the user to choose
        // which functions are invoked.
        int menu();

    private:
        // This is the head of the message list.
        m_node * head;

        // Recursive function to display the list.
        int display(m_node * head);
};

#endif

