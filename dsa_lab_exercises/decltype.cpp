#include <iostream>
using namespace std;
int main(){
    int x = 99;
    auto y = 67;
    decltype(x) z = 77;
    cout << "x = " << x << "y = " << y << "z = "<< z<< endl;
    return 0;
}