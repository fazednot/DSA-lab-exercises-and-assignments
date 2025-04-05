#include <iostream>
using namespace std;
int main(){
    getline(cin, input);
    cout <<"Input is "<< input << endl;
    input += "!";
    cout << "Input is now " << input << endl;
    return 0;
}