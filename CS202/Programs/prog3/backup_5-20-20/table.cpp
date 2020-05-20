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

    //Checking each derived type to determine which type of
    //object to copy over.
    zoom_id * test = dynamic_cast<zoom_id *>(copy.ptr);
    if(test) ptr = new zoom_id(*test);
    else
    {
        website * test = dynamic_cast<website *>(copy.ptr);
        if(test) ptr = new website(*test);
        else
        {
            app * test = dynamic_cast<app *>(copy.ptr);
            if(test) ptr = new app(*test);
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
           ptr = new app;
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
int data::compare(const data & to_cmp)
{
    //If there is no data, get the heck out of dodge.
    //ideally this shouldn't happen with the precautions
    //used in the tree structure.
    if(!this->ptr || !to_cmp.ptr) 
    {
        //This should not happen.
        cout << "\nNO POINTERS HERE.\n";
        return 0;
    }

    //Returning the string compare value of data's name.
    return ptr->compare(*to_cmp.ptr); 
}

//Display function for data.
void data::display(void) const
{
    if(!ptr) return;
    ptr->display();
}




//NODE CLASS

//Default constructor
node::node(void) : left(NULL),
    right(NULL) {}

//Copy constructor
node::node(const node & copy) : data(copy)
{
    //Copying over the contents of the left node.
    if(copy.left)
        left = new node(*copy.left);
    else left = NULL;

    //Copying over the contents of the right node.
    if(copy.right)
        right = new node(*copy.right);
    else right = NULL;
}

//Destructor
node::~node(void)
{
    //KEEP IN MIND SINCE THIS IS RECURSIVE, YOU NEED TO
    //DISCONNECT IT FROM THE REST OF THE TREE.

    //Deleting left node.
    if(left) 
    {
        delete left;
        left = NULL;
    }

    //Deleting right node.
    if(right) 
    {
        delete right;
        right = NULL;     
    }
}

//Left setter
void node::set_left(node * temp)
{
    left = temp;
}

//Right setter
void node::set_right(node * temp)
{
    right = temp;
}

//Returning the address of the left node
node *& node::get_left(void)
{
    return left;
}

//Returning the address of the right node
node *& node::get_right(void)
{
    return right;
}




//TREE CLASS

//Default constructor
tree::tree(void) : root(NULL) {}

//Copy constructor
tree::tree(const tree & copy)
{
    if(!copy.root)
    {
        root = NULL;
        return;
    }

    root = new node(*copy.root);
}

//Destructor
tree::~tree(void) 
{
    if(!root) return;
    delete root;
    root = NULL;
}

//Insert function
void tree::insert()
{
    node * temp = new node;
    temp->read();

    insert(root, temp);
}

//Recursive insert function
int tree::insert(node *& root, node * temp)
{
    if(!root)
    {
        root = temp;
        return 1;
    }

    if(temp->compare(*root) < 0)
        return insert(root->get_left(), temp);
    else
        return insert(root->get_right(), temp);
}

//Wrapper display function
void tree::display(void)
{
    if(!root) 
    {
        cout << "\nEmpty table.\n";
        return;
    }

    int result = display(root);
    cout << "\nInformation count: " << result << endl;
    return;
}

//Recursive display function
int tree::display(node * root)
{
    if(!root) return 0;
    int result = display(root->get_left());
    root->display();
    result += display(root->get_right());
    return 1 + result;
} 

//Search function
int tree::search(const str & srch)
{
    if(!root) return 0;
    cout << "\nSearching table for: " << srch;
}
