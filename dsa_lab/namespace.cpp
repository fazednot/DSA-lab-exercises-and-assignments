#include <iostream>
using namespace std;

namespace hi{
    int hello(){
        return 69;
    }
}
using namespace hi;
int main(){
   cout << hi::hello() << endl;
}
