#include <iostream>
using namespace std;
int main(){
    int number = -456;
    string day = "Monday";
    if (number > 0){
        cout << "The number is positive." << endl;
    }
    else if (number < 0){
        cout << "The number is negative." << endl;
    }
    else{
        cout << "The number is zero." << endl;
    }// if statement that checks if a number is positive, negative or zero

    int x;
    cin >> x;

    switch(x){
        case 1:
            cout <<"we have networking lab"<<endl;
            break;
        case 2:
            cout <<"we have Applied III class and Discrete Maths"<<endl;
            break;
        case 3:
            cout <<"we have Database and Networking class"<<endl;
            break;
        case 4:
            cout <<"we have DSA class with all the sections"<<endl;
            break;
        case 5:
            cout <<"A free day, enjoy it"<<endl;
            break;
        case 6:
            cout <<"We have OOP lecture in the morning and DSA lab after lunch"<<endl;
            break;
        defualt:
            cout <<"It's a holiday"<<endl;
            break;
    } // a switch statement that summarises my classes as a SiTE Section 2 student
    //my compiler says couldn't convert 'Monday' from 'const char [7]' to 'int'
    //after looking it up, I found out that the switch statement only works with integers and characters
    //I will have to use if else statements instead
    //however thiis my version of how I would use a switch statement just to show that I understand the concept
    for (int i = 100;i > 0; i--){
        cout << i << endl;
    }//a for loop conting down from 100 because why not?
    return 0;


}