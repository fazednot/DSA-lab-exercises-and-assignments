#include <iostream>
using namespace std;
struct Animal{
    int age;
    string name, sound;
}cat;
struct Dog{
    Animal dog;
    int maxSpeed;
}bobby;
struct Cat{
    Animal cat;
    int max_meows;
};
int main(){
    cat.age =  19;
    bobby.maxSpeed = 89;
    bobby.dog.sound = "woof";
    Cat kitty;
    kitty.max_meows= 99;
    Cat *ptr_kitty;
    *ptr_kitty = kitty;
    
    cout << ptr_kitty << endl;
    cout << kitty.max_meows <<endl;
    cout << bobby.maxSpeed <<endl;
    cout << bobby.dog.sound << endl;     

}