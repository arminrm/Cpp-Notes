#include <iostream>
using namespace std;

class Time {

    private:
        int hour, minute, second;
    
    public:
        Time();
        Time(int h, int m, int s);
        Time(const Time & source); //pass by reference necessary for copy constructor!!!

        //NOTE: There is already a default copy constructor and = operator

        int getHour();
        int getMinute();
        int getSecond();
        void setHour (int h);
        void setMinute (int m);
        void setSecond(int s);

        Time boobs(Time rhs);
        Time operator+ (Time rhs);
        Time operator- (Time rhs);
        Time & operator=(const Time & rhs); //rhs is a new object created when the function is invoked; constructor used to initialize it is copy constructor
        void print();  //pass by reference to save to cost of copying

};

Time :: Time() {

    hour = 0;
    minute  = 0;
    second = 0;
}

Time :: Time(int h, int m, int s) {

    hour = h;
    minute = m;
    second = s;
}

Time :: Time(const Time & source){  //const modifier protects against making any changes to the object we are passing by reference

    //NOTE: adding const after function prototype would protect against making any changes to object the method is invoked on 

    hour = source.hour;
    minute = source.minute;
    second = source.second;
}

void Time :: print(){

    cout << hour << " " << minute << " "<< second << " "<< endl;
}

Time Time :: operator+(Time rhs){ //cop made when object passed into function

    int TotalSeconds;
    Time sum;

    TotalSeconds = second + 60 * minute + 3600 * hour;
    TotalSeconds += rhs.second + 60 * rhs.minute + 3600 * rhs.hour;

    sum.hour = TotalSeconds/3600;
    sum.minute = (TotalSeconds - 3600*sum.hour)/60;
    sum.second = TotalSeconds%60;

    return(sum); //a copy of sum is made, invoking destructor after returned
}

Time Time :: operator-(Time rhs){

    int TotalSeconds;
    Time sum;

    TotalSeconds = second + 60 * minute + 3600 * hour;
    TotalSeconds -= rhs.second + 60 * rhs.minute + 3600 * rhs.hour;

    sum.hour = TotalSeconds/3600;
    sum.minute = (TotalSeconds - 3600*sum.hour)/60;
    sum.second = TotalSeconds%60;

    return(sum);
}

Time & Time :: operator=(const Time & rhs){

    hour = rhs.hour;
    minute = rhs.minute;
    second = rhs.second;

    return (*this); //return object in which method is being invoked on
}


//Time Time :: boobs(Time rhs){

    //hour = rhs.hour;
//}

int main(void){

    Time Z;

    Time X(5, 25, 30);

    X.print();
    Time Y(4, 30, 23);
    Y.print();

    Z = X + Y;
    Z.print();

    Z = X - Y;
    Z.print();
}

//you have to pass output stream/input stream by reference

//OBJECTS WITH POINTERS

class Time {

    private:
        struct _time * time_ptr; //store pointer which points to a dynamically allocated struct which contains info
    
    public:
        Time();
        Time(int h, int m, int s);
        Time(const Time & source); //pass by reference necessary for copy constructor!!!

        //NOTE: There is already a default copy constructor and = operator

        int getHour();
        int getMinute();
        int getSecond();
        void setHour (int h);
        void setMinute (int m);
        void setSecond(int s);

        Time boobs(Time rhs);
        Time operator+ (Time rhs);
        Time operator- (Time rhs);
        Time & operator=(const Time & rhs); //rhs is a new object created when the function is invoked; constructor used to initialize it is copy constructor
        void print();  //pass by reference to save to cost of copying

};

//constructor is invoked right after space for object is created, but before object is used

Time :: Time() {

    time_ptr = new struct_time;
    time_ptr -> hour  = 0;
    time_ptr -> minute = 0;
    time_ptr -> second = 0;
}

Time :: Time(int h, int m, int s) {

    time_ptr = new struct_time;
    time_ptr -> hour = h;
    time_ptr -> minute = m;
    time_ptr -> second = s;
}

//Memory leak if default destructor is invoked ---- "shallow" delete

Time :: ~Time(){

    //Delete struct dynamically allocated by the contructor

    delete time_ptr;
}

Time & Time ::operator=(const time & t){ //problem -> any operation on one object would change the other

    time_ptr = t.time_ptr;
    return (*this);

}

//correct way

Time & Time ::operator=(const time & t){

    time_ptr -> hour = t.time_ptr -> hour;
    time_ptr -> minute = t.time_ptr -> minute;
    time_ptr -> second = t.time_ptr -> second;

    return (*this); //enables chaining

}

//copy constructor

Time :: Time(const Time & src){

    time_ptr = new struct_time;
    time_ptr -> hour = src.time
}



