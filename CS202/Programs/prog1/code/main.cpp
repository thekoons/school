//File: main.cpp
//Author: Kunio Comey
//Class: CS202
//Date: 4/10/20
//Description: This is the main function used to test out the code. 

#include "str.h"
#include "title.h" 
#include "assignment.h"
#include "schedule.h"

using namespace std;


//Main Function
int main()
{
    m_list my_mess;
    a_list my_assign;
    schedule my_sched;

    int user_choice = 0;

    do
    {
        cout << "\nWelcome to the canvas simulation. Here is the menu:\n"
             << "1 --- Access Message List\n"
             << "2 --- Access Assignment List\n"
             << "3 --- Access Schedule\n"
             << "0 --- Quit\n"
             << "Please enter your choice (integer 0-3): ";

        cin>>user_choice; cin.ignore(100,'\n'); cin.clear();
        
        if(!user_choice)
            cout << "\nQuitting...";

        else if(user_choice == 1) 
            my_mess.menu();

        else if(user_choice == 2)
            my_assign.menu();

        else if(user_choice == 3)
            my_sched.menu();    

    } while(user_choice);

    return 1;
}

