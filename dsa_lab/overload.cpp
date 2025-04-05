#include <iostream>
using namespace std;
int multiply(int a, int b){
    return a*b;
};
double multiply(double a, int b){
    return a*b;
};
int multiply(int a, int b, int c){
    return a * b * c;
}
int main(){
    cout << multiply(2,3)<<endl;
    cout << multiply(2.0,3)<<endl;
    cout << multiply(2,3,4)<<endl;
}

