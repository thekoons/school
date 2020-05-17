//Kunio Comey
//CS202
//Program 3
//info.cpp

//This is the info, zoom_id, website, and application class
//implementation file.

#include "info.h"
using namespace std;

//INFO CLASS
//
//Default constructor
info::info(void) : priority(0) {}

//Copy constructor
info::info(const info & copy) : name(copy.name),
    priority(copy.priority) {}

//Destructor
info::~info(void) {}

//Info read function
void info::read_info()
{
    name.read();
    cout << "\nEnter your priority: ";
    cin >> priority; cin.ignore(100,'\n'); cin.clear();
}

//Display function for info
void info::display_info()
{
    name.display();
    cout << "\nPriority: " << priority;
}




//ZOOM ID CLASS 
//
//Default constructor
zoom_id::zoom_id(void) {}

//Copy Constructor
zoom_id::zoom_id(const zoom_id & copy) : info(copy), 
    id(copy.id) {}

//Destructor
zoom_id::~zoom_id(void) {}

//Reading function for zoom id
void zoom_id::read()
{
    cout << "\nPlease enter the name of this zoom room: ";
    info::read_info();
    cout << "\nEnter your zoom id: ";
    id.read();
}

//Display function for zoom id.
void zoom_id::display()
{
    cout << "\nZoom room name: ";
    info::display_info();

    cout << "\nZoom ID: ";
    id.display();
    cout << endl;
}




//WEBSITE CLASS
//
//Default constructor
website::website(void) {}

//Copy constructor
website::website(const website & copy) : info(copy),
    url(copy.url) {}

//Destructor
website::~website(void) {}

//Reading function for website
void website::read() 
{
    cout << "\nPlease enter the website name: ";
    info::read_info();
    cout << "\nEnter the website url: ";
    url.read();
}

//Display function for the website.
void website::display()
{
    cout << "\nWebsite name: ";
    info::display_info();

    cout << "\nWebsite url: ";
    url.display();
    cout << endl;
}




//APP CLASS
//
//Default constructor
app::app(void) {} 

//Copy constructor
app::app(const app & copy) : info(copy),
    link(copy.link) {}

//Destructor
app::~app(void) {}

//Reading function for application
void app::read() 
{
    cout << "\nPlease enter application name: ";
    info::read_info();

    cout << "\nEnter application link (for download or opening): ";
    link.read();
}

//Display function for application
void app::display()
{
    cout << "\nApplication name: ";
    info::display_info();

    cout << "\nApplication link: ";
    link.display();
    cout << endl;
}
