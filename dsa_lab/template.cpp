#include <iostream>
using namespace std;
template <typename myCustomType, typename anotherType>
myCustomType divide(myCustomType x, anotherType y){
    return  x + y;
}
int main(){
    divide(45.67,99);
}