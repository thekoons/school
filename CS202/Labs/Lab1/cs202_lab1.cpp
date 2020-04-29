#include "employee.h"
using namespace std;

const int MAX = 100;




//These functions will test the binary search tree for the employee reviews
//
//
//Testing the display 
int test_display(const hourly_employee &);

//Function to test the copy
int test_copy(const hourly_employee &);




//Main Function
//
//
//This code is to test out the hierarchy of the clases created
int main()
{
    char temp[MAX];
    char response;
    
    //experiment with the hourly employee class
    person person_applying;
    
    do
    {
       hourly_employee new_hire;
       cout <<"What is the name of the person applying for a job\n";
       person_applying.read();
       cout <<"\nWe received information about this person:\n";
       person_applying.display();
    
       cout <<"\nWould you like to hire them? Y or N ";
       cin >>response; cin.ignore(MAX,'\n');
       if (toupper(response) == 'Y')
       {
          new_hire.hire(person_applying);

          if(test_display(new_hire))
              cout<<"\nNo Roots\n";

          do
          {        
              cout <<"\nPlease enter their periodic performance review: ";
              cin.get(temp, MAX,'\n'); 
              cin.ignore(MAX, '\n');

              new_hire.performance_review(temp);
          } while (again());

          cerr <<"\n\nThis is the complete informatin about the new hire... ";
          //new_hire.display();
          test_display(new_hire);
       }
    } while (again());
    
    
    return 0;
}
    



//Function implementations
//
//
//Test Display Function
int test_display(const hourly_employee & temp)
{
    try temp.display();

    catch(...) 
    {
        cout<<"\nError has occured.\n";
        return 0;
    }

    return 1;
}

//Test Copy Function
int test_copy(const hourly_employee & temp)
{
    try 
        hourly_employee new_emp(temp);

    cathc(...)
    {
        cout<<"\nError has occured.\n";
        return 0;
    }

    return 1;
}
