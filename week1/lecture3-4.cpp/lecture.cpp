//Program organizaion and seperate compilation

#include <iostream>
using namespace std;

int main(){

    int squared (int);   //local definition -> only works in main -> only needs to know number and type of arguments (create global definition to reduce redundancy)
    int myNumber, myNumberSquared;

    cout << "Please enter a number: ";
    
}
//auto cannot be return value or parameter

//compiler takes source code and translate it to exectuable

//compile-time -> time compiler uses to generate executable (run time for compiler)
//runtime -> time in which your program is running

//type of errors: syntax errors, semantic errors (ex. assigning float to string), run-time errors (1 / 0), logical errors -> development cycle

//ide inititiates compiling

//command line prompt -----> 1) g++ myprog.cc -o myprog.exe 2) myprog.exe ---> ide automates this process

//**************//

//organizing code into single file: 1) collaboration 2) shorter compilation

// 3 files -> main.cc, squared.cc, squareRoot.cc

//file: main.cc

#include <iosteam>
#include "squared.h" //go look for this file in current directory, use its contents -> header file, quotes indicate this is my file
#include "squareRoot.h" //contains function prototypes, command line used to link the files
using namespace std;

//Definition file for squared module (square.h)

int squared(int)

//implementation file (square.cc)

#include "squared.h"

float squareRoot (int number){

    return (number * number)
}

//g++ -E -P main.cpp -> process includes header file in source code

//compile in single command: g++ main.cpp squared.cpp squareroot.cpp -o myprog.exe  (do not have to specify header files)

    //Seperate compilation: 
    
    // 1) main.cpp -> g++ -> partial executable (main.o) (cannot execute it - it is not an executable, object file) ---> g++ -c main.cc (-c means only compile)
    // 2) squared.cpp -> g++ -> squared.o 
    // 3) squareRoot.cpp -> g++ -> squareRoot.o
    
        // 4) take instructions from each object file, create myprog.exe (linking) ---> g++ main.o squared.o squareRoot.o -o myprog.exe

        // changing one file will require relinking -> linking is much faster than compiling 

    //Command line utility (Make) that keeps track of what changed and issues the right set of commands

//including square.h --> double declarations if you include the file twice

    //square.h:

    #pragma once
    // include only once
    int my_global;
    int squared(int);

    //older method:

    bool firstIteration = True;

    while (condition){

        if (firstIteration){

            firstIteration = false;
        }
        ...
    }

    //#define a, #undefine a --> declaration puts var in memory

    //#ifndef FirstInclusion  -> if not defined, define it   -> whats between ifndef and endif is processed
    //#define FirstInclusion

    //squared.h:
    #ifndef _squared_h
    #define _squared_h //by convention
    int my_global;
    int squared(int);
    #endif

//.h files serve as a contract between the collaborators
//facilitate software release

//Never include source files, only header files ---> it compiles the entire code, ruins the point
