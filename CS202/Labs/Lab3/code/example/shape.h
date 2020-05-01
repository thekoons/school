//Header file to be used with main.
//Will contain all of the classes used in main.
#include <iostream>
#include <cstdlib>
using namespace std;

//Abstract base class.
class shape
{
    public:
        //virtual ~shape();
        virtual int draw()=0;
};

//Derived class that actually has functionality.
class circle : public shape
{
    public:
        //~circle();
        int draw() {
            cout << "\nDrawing Circle";
            return 1;
        }
};

//Derived class similar to class above.
class triangle : public shape 
{
    public:
        //~triangle();
        int draw() {
            cout << "\nDrawing Triangle";
            return 1;
        }
};

//Object to hold the different shapes.
class shape_list
{
    public:
        // Default constructor.
        shape_list();

        // Copy constructor.
        shape_list(const shape_list & copy);
           
        // Default destructor.
        ~shape_list();
            
        // Function to draw all of the shapes in here. Draw just shows 
        // which objects are in each list.
        int draw();
          
    protected:
        shape ** array;
        int size;
};

