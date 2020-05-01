//Implementation file for the shape classes.

#include "shape.h"

//Default constructor.
shape_list::shape_list() 
{
    cout<< "\nHow big do you want this list to be?: ";
    cin>>size; cin.ignore(100,'\n'); 
    array = new shape * [size];

    //Setting each element randomly to circle or triangle..
    for (int i = 0; i < size; ++i)
    {
        int rando = rand() % 2;

        //Switch statement to make these guys random.
        switch (rando)
        {
            case 0:
               array[i] = new circle;
               break;

            case 1:
               array[i] = new triangle;
               break;

            default:
               cout << "\nThis got fucked somehow.";
        }
    }
}


//Copy Constructor
shape_list::shape_list(const shape_list & copy) 
{
    //Copy algorithm to make sure we copy over the right types.
    size = copy.size;
    array = new shape * [size];

    for(int i = 0; i < size; ++i)
    {
        //Checking if array[i] is a circle object.
        circle * ptr = dynamic_cast<circle *>(copy.array[i]);
        if(ptr) array[i] = new circle;

        //If that didn't work, then move onto the next type to check.
        else
        {
            //Checking if array[i] is a triangle object.
            triangle * ptr = dynamic_cast<triangle *>(copy.array[i]);
            if(ptr) array[i] = new triangle;
        }
    }
}


//Destructor function
shape_list::~shape_list() 
{
    for(int i = 0; i < 2; ++i)
    {
        delete array[i];
        array[i] = NULL;
    }
    delete [] array;
    array = NULL;
}


//Implementing the draw function.
int shape_list::draw() 
{
    for(int i = 0; i < size; ++i)
        array[i]->draw();
    cout << endl;

    return 1;
}

