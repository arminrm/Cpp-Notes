//Classes and Objects
#include <iostream>
using namespace std;


class DayOfYear {

    //data members
    private: //these members could only be accessed by member functions (i.e cannot be accessed by main)
        int day;   
        int month;

    //function members i.e. methods of the class

    public: //members could be accessed by anyone
             DayOfYear(); // constructor - same name of class, member of class, no return type
             DayOfYear(int d, int m); //diff type of arguments
             ~DayOfYear();  //destructor; takes no argument, no return type; public, starts with ~
        void setDay(int d);
        void setMonth(int m);//you could write function in prototype
        void print();
        void addOne();

};

DayOfYear :: ~DayOfYear(){}

void DayOfYear :: setDay(int d){  //setDay belongs to class which is DayOfYear

    day = d;
    (*this).day = d;  //One or the other; "this" is the address of the object the method is invoked on
}

void DayOfYear :: setMonth(int m){

    month = m;
}

void DayOfYear :: print(){

    cout << day << '/' << month << endl;
}

void DayOfYear :: addOne(){  //able to access fields of any object that is of that class type; member of class, not object

    DayOfYear temp;
    temp.day = 1;
    temp.month = 1;

    day = day + temp.day;
    month = month + temp.month;
}

DayOfYear :: DayOfYear(){  //automatically invokes function

    day = 1;
    month = 1;
}

DayOfYear FirstOfJuly;
DayOfYear Christmas;

//field access operators could be used to access public members in a class
    //methods could be invoked in the same way  ---> cannot invoke methods on their own, must be invoked on object


//why provide a function to change a data member when we can access member directly?
    //2 reasons: 1) may want to provide error checking 2) Will now prevent access to data members

    //we do so to encapsulate our object i.e. prevent access to its internal data

//Organzation:
 
    //DayofYear.h --> Class definition
    //DayofYear.cpp --> Blueprint implementation
    //main.cpp --> uses DayofYear class, link with DayofYear.cpp file

//Initialization of objects:

    //Constructor --> A function that you write and that is automatically called everytime an object is created, used to initialize object
        //Default constructor = no arguments

        //You can have as many constructors as you want, arguments must be different or order!


    //Everytime object is declared, constructor must be called -> constructor given to you if not provided
        //Must write a default constructor !!!!!


    //Default member initializations

        // int day = 1;
        //int month = 1;   --> You do not need a default constructor

        //g++ "-std=c++11" -c file.cpp


//Destructors

    //Automatically calls function when an object is destroyed (i.e. end of a function)

//The "this" Pointer

    //Every method is given the address of the object on which it is invoked
        //This address is stored in the "this" pointer; DayofYear *this created automatically



