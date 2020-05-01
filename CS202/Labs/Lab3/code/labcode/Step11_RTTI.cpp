#include "manager.h"
using namespace std;

//FILL in the blanks for Step #11 creating the manager copy constructor

//Step 11b - Add in the initialization list (uncomment the code)
manager::manager(const manager & old_manager) : salaried_employee(old_manager),
    group(old_manager.group), num_employees(old_manager.num_employees)
/* 
  salaried_employee(______),
  group_name(old_manager.________), num_employees(old_manager.______)
  */
{
/*
    //Step 11e - Fill in the blanks to create an array of employee pointers
    group = new ___________  [________________];
    for (int i = 0; i < num_employees; ++i)
    {
        employee * temp = old_manager.group[i];

        //Step 11g - Fill in the blanks for using dynamic cast
        _____________ *  ptr = dynamic_cast<__________> (temp);
        if (ptr)
            group[i] = new salaried_employee(*ptr);
        else 
        {
           __________  * ptr = dynamic_cast<__________> (temp);
           if (ptr) group[i] = new full_time(*ptr);
           else
           {
              ____________ * ptr = dynamic_cast<____________> (temp);
              if (ptr) group[i] = new hourly_employee(*ptr);
              else group[i] = NULL;
            }
         }
    }
    */
    
    group = new employee * [num_employees];
    for (int i = 0; i < num_employees; ++i)
    {
        employee * temp = old_manager.group[i];

        // Checking if the pointer is pointing to a salaried employee.
        salaried_employee * ptr = dynamic_cast<salaried_employee *>(temp);  
        if(ptr) 
            group[i] = new salaried_employee(*ptr);
        else
        {
            // Checking if the ptr is pointing to a full time employee.
            full_time * ptr = dynamic_cast<full_time *>(temp);
            if(ptr) group[i] = new full_time(*ptr);
            else
            {
                // Checking if the ptr is pointing to an hourly employee.
                hourly_employee * ptr = dynamic_cast<hourly_employee>(temp);
                if(ptr) group[i] = new hourly_employee(*ptr);
                else group[i] = NULL;
            }
        }
    }
}

