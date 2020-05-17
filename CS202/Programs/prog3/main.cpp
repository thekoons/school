//Kunio Comey
//CS202
//Program 3
//main.cpp

#include "str.h"
#include "info.h"
#include "table.h"

using namespace std;

//Main function for the program.
int main()
{
    //This main function needs to just hold the menu
    //class, which will hold all of the data to make 
    //a new folder.
    info ** array = new info * [3];
    array[0] = new zoom_id;
    array[1] = new website;
    array[2] = new app;

    //Testing read.
    for(int i = 0; i < 3; ++i)
        array[i]->read();

    //Testing display.
    for(int i = 0; i < 3; ++i)
        array[i]->display();

    //Deleting the array.
    for(int i = 0; i < 3; ++i)
        delete array[i];
    delete [] array;

    return 1;
}
