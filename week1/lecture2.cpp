//Introduction to C++

//Basic structure of C++ program
//Understand how very basic I/O is done in C++

//Reference: Textbook ch. 1-5, 7

#include <iostream>  //standard I/O library in C++  -- defines namespace std
using namespace std; //using something of type namespace and it is std -> namespace is a container of all the names that exist in your code

//within iostream, namespace in container which defines names

int main(){

    cout << "Hello World!" << endl;  //"cout" -> send it to the output, defined in namespace "<<" -> inserstion operator 

    std::cout << "Hi" << std::endl;

    return 0;
}

int main(){

    int value;
    cout << "Enter an interger: ";
    cin >> value;   //Variabele to read into; Input in C++
    cout << "The integer  is: " << value << endl;

    return 0;
}

//variable declarations are identitical in C

auto count = 6;       //type of count is determined based on the type of the initializer
auto velocity = 8.3;  
auto maxCount = count;

//Why auto?

//Reduce the use of long type names, could be used when defining own class type !!!
// You don't to go through all the code and change the types of all variables

#include <string>  //C++ has string library

int main(){

    string FirstName;
    string LastName;

    string Name = FirstName + " " + LastName;
    
    return 0;

}

//Functions

//PASSING BY VALUE

int squared(int v){

    int temp;
    temp = v * v;

    return(temp);
}

int main(){

    int x, y;

    x = squared(y);  //function is called/invoked, make v a copy of y (v = y)
}

//PASSING BY REFERENCE (C++ version)

void swap(int & lhs, int & rhs){  //This means you are passing by refernce, C++ works under the hood

    int temp;
    temp = lhs;
    lhs = rhs;
    rhs = temp;

}

