#include <iostream>
using namespace std;
int main(){
    int age = 20;
    cout << "Age is: " << age << endl;
    age +=1;
    cout << "Age is: " << age << endl;
    string _candrive = (age >= 18) ? "Yes, you can" : "No, you can't";
    cout << _candrive << endl;
    return 0;


}