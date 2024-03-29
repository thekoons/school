//Kunio Comey
//Cs202
//Program 3
//table.h

#include "info.h"

#ifndef TABLE_H
#define TABLE_H

#include <fstream>

//Data class will hold an info base pointer so that we
//can make each data a different type of "info" (zoom link,
//website, or application).
class data
{
    public:
        //Constructors
        data(void);
        data(const data &);

        //Destructor
        ~data(void);

        //Read, compare, and display functions to call the
        //virtual functions on ptr.
        void read(void);
        int compare(const data &);
        int compare(const str &);
        void display(void) const;

        data & operator=(const data &);

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

        node & operator=(const node &);

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
        void insert(node * temp);

        int search();
        void display();
        int remove();

        //Reading and writing function for the external data.
        int read_ext();
        int write_ext();

    private:
        node * root;

        int insert(node *& root, node * temp);
        int display(node * root);
        int search(node * root, const str & srch);
        int remove(node *& root, const str & srch);
        int removal_cases(node *& root);
        data *& special_traverse(node *& root);
};

#endif
