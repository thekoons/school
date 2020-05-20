#include "str.h"
#include "info.h"
#include "table.h"

using namespace std;

//OPERATOR OVERLOAD FOR INFO CLASS.
info & info::operator=(const info & copy)
{
    name = copy.name;
    priority = copy.priority;
    return *this;
}

info & info::operator+=(const info & copy)
{
    name += copy.name;
    if(priority > copy.priority)
        priority = copy.priority;
    return *this;
}

ostream & operator<<(ostream & out, const info & object)
{
    out << object.name << endl;
    out << object.priority;
}

istream & operator>>(istream & in, const info & object)
{
    in >> object.name; in.ignore(100,'\n');
    cout << "Enter priority ";
    in >> object.priority;
    return in;
}

/*
info info::operator+(const info & to_add)
{
    info temp(*this);
    temp += to_add;
    return temp;
}
*/

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
