#include "manager.h"
using namespace std;


//Step 8a - Finish the manager constructor
//
//FINISH THIS FUNCTION.
//HINT - it needs an initialization list to set up the
//managers information
manager::manager( const salaried_employee & managers_information) : 
    salaried_employee(managers_information)
 {
    cout <<"\nPlease enter the group name: ";
    group_name.read();
    cout <<"\nHow many group_members? ";
    cin >> num_employees; cin.ignore(100,'\n');

    //COMPLETE THIS FUNCTION - allocating the dynamic array of
    //employees in this group:
    group = new employee*[num_employees];
    
    for(int i = 0; i < num_employees; ++i)
        group[i] = NULL;

    /*
    employee ** ptr = group;
    int count = 0;
    initialize(ptr, count);
    */
}

/*
int manager::intialize(employee ** ptr, int & count)
{
    if(count == num_employees) return 1;
    *ptr = NULL;
    return initialize(++ptr, ++count);
}
*/

//Step 8b - Implement the manager destructor
//
//Deallocate the array of employee pointers
manager::~manager()
{
    for(int i = 0; i < num_employees; ++i)
    {
        delete group[i];
        group[i] = NULL;
    }

    delete [] group;
}

// *********** STOP ************* 
// now you will be workiing on experiencing dynamic binding by
// modifying main. Read the lab manual for Step 9

//Step 10 - Experiencing RTTI
//
//THIS FUNCTION REQUIRES RTTI!!!
void manager::add_to_group( const employee & to_add)
{
    //Algorithm: Need to traverse to a spot that is null.
    //  Once you hit the spot, need to have the ptr ready
    //  to copy over.

    employee * temp = group[0];

    for(int i = 0; i < num_employees && group[i]; ++i)
        temp = group[i];

    //Very ugly but we will see if this works.
   const part_time * ptr = dynamic_cast<const part_time *>(&to_add);  
   if(ptr) 
   {
       cout << "\nAdding a part timer.\n";
       *temp = new part_time(to_add);
   }
   else
   {
       const full_time * ptr = dynamic_cast<const full_time *>(&to_add);
       if(ptr) *temp = new full_time(to_add);
       else
       {
           const salaried * ptr = dynamic_cast<const salaried *>(&to_add);
           if(ptr) *temp = new salaried(to_add);
       }
   }
}

//SAMPLE
void manager::display() const
{
    cout <<"MANAGER ";
    salaried_employee::display();
    cout <<"\nGROUP NAME: ";
    group_name.display();
    for (int i = 0; i < num_employees; ++i)
      if (group[i]) group[i]->display();
}   
