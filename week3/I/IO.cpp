#include <iostream>
using namespace std;

//white spaces or returns act like delimiters

//cin stops extraction when input stream does not match what it reads (i.e. ".")
    //QUESTION: How are decimal points extracted from input stream??

//cin.ignore used to discard part of stream (i.e. cin.ignore(1000, " "))
//cin.ignore(number, character) -> takes no more arguments


int main(){

    int bob;

    cin >> bob;

    if (cin.fail()){ //function checks to see if the immediately preceeding extraction from the input stream has raised the fail flag (flag set to fail if couldn't extract)

        cout << "That was shit" << endl; 

        cin.clear(); //This function clears the flags (to normal; flags are persistant)
        cin.ignore(1000, '\n'); //Function ignores chars in the stream up to x or until '\n' is found  -> stream is refreshed, new input is allowed
    }

    return 0;
}

//end-of-file error indicates that there is no more input to be expected

    //enocuntering eof when more input is expected is an error that raises two flags within cin: fail and eof

    // eof = ctrl+d
    
    //use cin.fail in condition -> encompasses both eof and fail flags


//The getline function takes the entire input stream and places it in its string argument

#include <iostream>
using namespace std;

int main(){

    string fullName;
    getline(cin, fullName); //alse cin.getline(fullName, 256) -> requires length of the string
    cout << fullName;
    return 0;
}

//User-Created streams

    //C++ allows you to create streams and use them like cin cout


#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){

    int anInteger;
    string inputLine;

    getline (cin, inputLine);

    stringstream myOwnStream (inputLine); //creating variable of type stringstream; initialize using inputLine

    myOwnStream >> anInteger; 

    return 0;
}

//File Streams

    //Takes input from files, not keyboard

#include <iostream>
#include <fstream>
using namespace std;

int main(){

    ifstream inFileStream;
    int a;

    inFileStream.open("inputfile");

    inFileStream >> a;

    cout << a << endl;

    inFileStream.close();

    return 0;
}

int main(){

    ofstream outFileStream;
    int a = 8;

    outFileStream.open("outputfile");

    outFileStream << a;

    outFileStream.close();

    return 0;
}

//The output stream

    //cout has a set of output manipulator that allow you to formt the output

#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    int myVar = 503;

    cout << myVar << endl;
    cout << setw(8) << myVar << endl;  //sets width of output to 8  //non-sticky
    cout << myVar << endl;
    cout << setfill('0') << setw(8) << myVar << endl; //ex. 00000503   //sticky - character would be used for fill

    return 0;
}

int main(){

    float myVar = 3.287901;

    cout << setprecision(3)  << myVar << endl;  //outputs 3.29

    return 0;
}

//Redirection (unix)

// % myprog.exe > outfile  (all output goes to outfile)
// %myprog.exe  < infile   (all input taken from file)
        // < infile > outfile

