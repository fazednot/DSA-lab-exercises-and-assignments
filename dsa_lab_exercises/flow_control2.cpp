#include <iostream>
using namespace std;
int main(){
    int input;
    cout << "Enter a non-negative integer: ";
    cin >> input;
    if (input >= 0){
        int fact = 1;
        for (int i = 1; i<=input; i++){
            fact *= i;
            }
        cout << "Factorial of " << input << " is " << fact << endl;    
    }
    else{
        cout << "You have not entered a non-negative number." << endl;
    }
    return 0;
}