#include <iostream>
using namespace std;
int main(){
    int var = 10;
    cout << "Value of var: " << var << endl;
    var += 5;
    cout << "Value of var: " << var << endl;
    var -= 3;
    cout << "Value of var: " << var << endl;
    bool isGreater = (var > 10)? true : false;
    cout << isGreater << endl;

    return 0;
}