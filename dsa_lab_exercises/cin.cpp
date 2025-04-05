#include <iostream>
using namespace std;
int main(){
    string input;
    cout << "Enter your name: ";
    cin >> input;
    cout << "Hello, " << input << endl;
    return 0;
}
// after a thorough reading I have found out that cin stops reading when it encounters a whitespace character because it is designed that way to read a single word at a time.
// to make it easier to read individual data.if we need to include the parts after spaces we can use the getline() function