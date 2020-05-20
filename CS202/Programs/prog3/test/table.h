//Kunio Comey
//Cs202
//Program 3
//table.h

#include "info.h"

#ifndef TABLE_H
#define TABLE_H

//Data class will hold an info base pointer so that we
//can make each data a different type of "info" (zoom link,
//website, or application).
class data
{
    public:
        //Constructors
        data(void);
        data(const data &);
        ~data(void);

        //Read, compare, and display functions to call the
        //virtual functions on ptr.
        void read(void);
        int compare(const data &);
        void display(void) const;

    protected:
        info * ptr;
};

//Node class will be derived from data and will hold the
//addresses of the left node and the right node. This will
//be used for the tree data structure.
class node : public data
{
    public:
        //Constructors
        node(void);
        node(const node &);
        ~node(void);

        //Setters
        void set_left(node *);
        void set_right(node *);

        //Getters
        node *& get_left(void);
        node *& get_right(void);

    private:
        node * left;
        node * right;
};

//Tree class will be the data structure that holds the different
//nodes.
class tree
{
    public:
        //Constructors
        tree(void);
        tree(const tree &);
        ~tree(void);

        //Insert, search, display, and remove function.
        void insert();
        int search(const str &);
        void display();
        int remove(const str &);

    private:
        node * root;

        int insert(node *& root, node * temp);
        int display(node * root);
};

#endif
