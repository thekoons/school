//Kunio Comey
//CS202
//Program 3
//info.h

//This is the header file for info.h which holds
//the class hierarchy for info (base class), zoom_id,
//website, and news_source.

#include "str.h"

#ifndef INFO_H
#define INFO_H

//Info class will be an abstract base class that will
//hold the common elements in the hierarchy and hold
//the virtual functions.
class info
{
    public:
        //Constructors and destructor.
        info(void);
        info(const info &);

        //Virtual destructor
        virtual ~info(void);

        //Read and prompt function and display function.
        void read_info();
        void display_info();

        //Compare function to compare the names.
        int compare(const info & to_cmp) const;
        
        //Virtual display and read function that will connect to 
        //the derived classes.
        virtual void read()=0;
        virtual void display()=0;

    protected:
        str name;
        int priority;
};

//The zoom_id class will hold all of the elements of
//info and then add on the string id.
class zoom_id : public info
{
    public:
        //Constructors and destructors
        zoom_id(void);
        zoom_id(const zoom_id &);

        ~zoom_id(void);
        
        void read();
        void display();

    protected:
        str id;
};


//The website class will hold the same elements as
//info with a string url for the website.
class website : public info
{
    public:
        //Constructors
        website(void);
        website(const website &);

        ~website(void);

        void read();
        void display();

    protected:
        str url;
};


//The application class will hold the same elements
//as the info class with a string app_link to link
//a download to the app (or take you directly to the 
//app hypothetically).
class app : public info
{
    public:
        //Constructors
        app(void);
        app(const app &);

        ~app(void);

        void read();
        void display();

    protected:
        str link;
};

#endif
