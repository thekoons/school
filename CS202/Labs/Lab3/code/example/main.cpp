//Practicing dynamic binding.
#include "shape.h"

// Testing out having an array of different objects from
// the same hierarchy and figuring out how to perform dynamic
// binding and how to use RTTI with dynamic cast.
int main()
{
    shape_list list1;
    list1.draw();

    //Commented out to see if the problem occured in the
    //copy constructor.
    shape_list copy(list1);

    copy.draw();

    return 0;
}

//This program is finished! Review:
//  - Use dynamic binding for having a data structure of
//      different types of classes. This allows the client
//      to easily call different functions of different
//      objects in the same hierarchy.
//
//  - Use RTTI for copying over contents so that we can know
//      what type of object we want to insert into the copy
//      list and have it match the source list. RTTI probably
//      has other uses but for the scope of this class we should
//      implement them for copy constructors.
//
//Topics not covered:
//  - Virtual Destructors. We need to see how virtual destructors
//      connect from the base class pointer to the derived class.

