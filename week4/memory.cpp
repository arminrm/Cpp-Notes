#include <iostream>
using namespace std;

//pointers, scopes and arrays

// pointers are variables (ex. int*px is a pointer to an integer, has its own adress in memory)

int x = 2;
int y = 1;

int* px;
float* py;

px = &x; //& is the adress operator -> stores address of memory location
y = &y;

*px = 3; //* dereference operator: go to adress stored
*py = 5.2;

//we commonly use pointers to create new variables while a program is executing -> dynamic data

int *px;
px = new int; //new returns address while integer created

*px = 5;

//opposite of new is delete -> analogous to "free"

delete px; //you cannot delete anything you did not create with new - you are deleting what px is pointing to

//address of deleted item sill stored in px -> dangling pointer
px = nullptr; //nullptr is NULL -> eliminates dangling pointer

//pointers to structs

struct node* ptr;

struct node{

    int ID;
    float value;
};

ptr = new struct node; //returns address of struct node - allocate enough memory for node struct

(*ptr).ID = 2;
(*ptr).value = 6.2;

struct node* pptr;
pptr = ptr;

ptr = new struct node;  //points to new block in memory
(*ptr).ID = 3;  //ptr -> Id = 3
(*ptr).value = 8.1;

struct node {

    int ID;
    struct node* next;

};

#include <iostream>
using namespace std;

int main(){

    struct node* head;
    struct node* ptr;

    head = new struct node; //allocates memory for type struct node
    (*head).ID = 0;
    (*head).next = nullptr;

    ptr = new struct node; 
    (*ptr).ID = 1;
    (*ptr).next = nullptr;

    (*head).next = ptr;

}

//dynamic allocation of objects

class DayOfYear {

    //data members
    private: //these members could only be accessed by member functions (i.e cannot be accessed by main)
        int day;   
        int month;

    //function members i.e. methods of the class

    public: //members could be accessed by anyone
             DayOfYear(); // same name of class, member of class, no return type
             DayOfYear(int d, int m); //diff type of arguments
             ~DayOfYear();  //destructor; takes no argument, no return type; public
        void setDay(int d);
        void setMonth(int m);   //you could write function in prototype
        void print();
        void addOne();

};

int function(){

    DayOfYear* day1;
    day1 = new DayOfYear;  //which constructor has been invoked? -> initiailization after type

    DayOfYear* day2;
    day2 = new DayOfYear(1,1);

    delete day1; //follow pointer, delete object
    day1 = nullptr;


}

//scope of variables -> Variable is visible from the point of declaration to the end of the code block in which it is declared, except where it is eclipsed


//scope of dynamic data

void allocate_int(){

    int *q;  //local variables
    q = new int;
    *q = 5;  //you would want to return q

}

//local variables of function disappears, dynamically allocated remains

    //scope of dynamic data is from the point they are allocated to the point at which explicity deleted
    //DYNAMICALLY ALLOCATED!!
        //"address of variable out of scope"


//Types of variables:

        //Global variables //automatic 
        //Local Variables  //automatic created on "stack"
        //Function arguments //automatic created on "stack"
        //Dynamic variables //User-managed created on "heap" -> you manage their lifetime


//Memory regions: Code (instructions), Data (Global/static variables), Stack (Automatic variables), Heap (Dynamic Variables)

//Arrays

//Size of the array must be a compile-time known constant

//The name of the array can be used as a pointer to the first element of the array

int function2(){

    int* myarray;
    int size;

    cin >> size;

    myarray = new int[size]; //I want to allocate an array of integers; pointer to the first element of the array I created

    myarray[0] = 0;

    delete [] myarray; //bracket since myarray points to first element of an array of integers

    myarray = NULL;

}

//if we know the size of array, we do not need to dynamically allocate

struct node{

    int ID;
    struct node* next;

};

int size;

cin >> size;
struct node* a;

a = new struct node[size];

delete [] a;
a =nullptr;

//Array of pointers

int *a[100];

//or

int **a;
cin >> size;

a = new int*[size];


for (int i = 0; i < size; i++){

    a[i] = new int;
}

//deletion

for (int i = 0; i < size; i++){

    delete a[i]; //delete what pointer in array points to
    a[i] = NULL;

    delete [] a;
    a = nullptr;
}

//struct node example

cin >> size;
struct node** a;
a = new struct node*[size];

for (int i = 0; i < size; i++){

    a[i] = new struct node;
}

for (int i = 0; i < size; i++){

    a[i] -> ID = i;
}

//arrays of objects

DayOfYear a[10]; //default constructor -> must invoke default constructor CANNOT SELECT ANOTHER CONSTRUCTOR
//when elements are created in bulk, only the default constructor could be invoked

//dynamic creation

DayOfYear* a;

a = new DayOfYear[size];

delete [] a; //destructor invoked

//Array of pointer to objects

DayOfYear *a[10]; //no constructor is called

for (int i = 0; i < 10; i++){

    a[i] = new DayOfYear(1, 2);
}

for (int i = 0; i < 10; i++){

    delete a[i];
}

