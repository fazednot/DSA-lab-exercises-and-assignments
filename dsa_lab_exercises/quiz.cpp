#include <iostream>
using namespace std;
void sumOfDigits(int x){
    int sum = 0;
    while(x > 0){
        sum += x % 10;
        x /= 10;
    }
    cout << sum << endl;

}
int sumOfDigitsRecursively(int x){
    if(x == 0){
        return 0;
    }
    return x % 10 + sumOfDigitsRecursively(x / 10);
}

int main(){
    int x = 12345;
  
    sumOfDigitsRecursively(x);
    return 0;
}
