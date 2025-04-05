#include <iostream>
using namespace std;
void duplicate(int a, int b, int c){
    a *= 2;
    b *= 2;
    c *= 2;
}
void duplicate1(int &a, int &b, int &c){
    a *= 2;
    b *= 2;
    c *= 2;
}
int recursive(int a){
    int x = 1;
    return a * recursive(a-1);
}
int main (){
    int x = 1, y = 3, z = 7;
    cout << recursive(7)<<endl;
    cout << x << " " << y << " " << z << endl;
    return 0;
}
