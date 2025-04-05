#include <iostream>
using namespace std;
int main(){
    int age = 19;
    float gpa = 3.43;
    bool isFreshman = true;
    char grade = 'B';

    cout << "Age: " << age << endl; 
    cout << "GPA: " << gpa << endl;
    cout << "Is Freshman: " << isFreshman << endl;
    cout << "Grade: " << grade << endl;

    age += 1;
    gpa = ((gpa * 37) + (3.46 * 70))/107;
    isFreshman = false;
    grade = 'A';

    cout << "Age: " << age << endl; 
    cout << "GPA: " << gpa << endl;
    cout << "Is Freshman: " << isFreshman << endl;
    cout << "Grade: " << grade << endl;

    return 0;



}