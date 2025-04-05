#include <iostream>
using namespace std;
class Student{
    private:
        int age;
        void
    protected:
        double gpa;
        bool _isMarried;
    public:
        string name, location;
        string getLocation(){
            cout << name << " Lives at "<<location<<endl;

        }        
};
class Teacher : public Student{
    public:
        int id;
};
int main (){
    Student Aman, Abebe;
    Aman.name = "Aman";
    Aman.location = "Addis Ababa";
    Abebe.name = "Abebe";
    Abebe.location = "c-137";
    Abebe.getLocation();
    Teacher abraham;
    abraham.gpa = 4.00;
    return 0;
    

}