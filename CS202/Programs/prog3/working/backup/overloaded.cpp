#include "str.h"
#include "info.h"
#include "table.h"

using namespace std;

//OPERATOR OVERLOAD FOR INFO CLASS.
//Assignment operator overload.
info & info::operator=(const info & copy)
{
    name = copy.name;
    priority = copy.priority;
    return *this;
}

//Plus equals operator overload.
info & info::operator+=(const info & copy)
{
    name += copy.name;
    if(priority > copy.priority)
        priority = copy.priority;
    return *this;
}

/* Couldn't implement the + operator without hurting
 * dynamic binding. There are problems with dynamic
 * binding and return by value. Can only return by ref.
 */ 

//This operator will only work if we have one addition statement
//in the right side. Will also act as the += operator so have to
//be careful.
info & info::operator+(const info & to_add)
{
    /*
    info temp;
    temp.name = this->name;
    temp.priority = this->priority;
    temp.name += to_add.name;
    temp.priority = to_add.priority;
    */

    return *this += to_add;
} 

//Insertion operator overload.
ostream & operator<<(ostream & out, const info & object)
{
    out << object.name 
        << "\nPriority: " 
        << object.priority; 

    return out;
}

//Extraction operator overload.
istream & operator>>(istream & in, info & object)
{
    object.read_info();
    return in;
}

//Relational operators
bool operator < (const info & op1, const info & op2)
{
    return op1.name < op2.name;
}

bool operator <= (const info & op1, const info & op2)
{
    return op1.name <= op2.name;
}

bool operator > (const info & op1, const info & op2)
{
    return op1.name > op2.name;
}

bool operator >= (const info & op1, const info & op2)
{
    return op1.name >= op2.name;
}

bool operator == (const info & op1, const info & op2)
{
    return op1.name == op2.name;
}

bool operator != (const info & op1, const info & op2)
{
    return op1.name != op2.name;
}

//ZOOM ID CLASS OPERATOR OVERLOAD
zoom_id & zoom_id::operator=(const zoom_id & copy)
{
    //Checking for self assignment
    if(this == &copy) return *this;

    this->info::operator=(copy);
    id = copy.id;

    return *this;
}

//WEBSITE CLASS OPERATOR OVERLOAD
website & website::operator=(const website & copy)
{
    //Checking self assignment
    if(this == &copy) return *this;
    
    this->info::operator=(copy);
    url = copy.url;

    return *this;
}

//APPLICATION CLASS OPERATOR OVERLOAD
app & app::operator=(const app & copy)
{
    //Check self assignment
    if(this == &copy) return *this;

    this->info::operator=(copy);
    link = copy.link;

    return *this;
}

//DATA CLASS OPERATOR OVERLOAD
data & data::operator=(const data & copy)
{
    //Check self assignment
    if(this == &copy) return *this;
    
    if(ptr) delete ptr;

    zoom_id * check = dynamic_cast<zoom_id *>(copy.ptr);
    if(check) ptr = new zoom_id(*check);
    else
    {
        website * check = dynamic_cast<website *>(copy.ptr);
        if(check) ptr = new website(*check);
        else
        {
            app * check = dynamic_cast<app *>(copy.ptr);
            if(check) ptr = new app(*check);
        }
    }

    return *this;
}

//NODE CLASS OPERATOR OVERLOAD
node & node::operator=(const node & copy)
{
    if(this == &copy) return *this;

    this->data::operator=(copy);

    return *this;
}
