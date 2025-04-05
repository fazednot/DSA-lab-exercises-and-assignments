#include <iostream>
#include <string>
#define TAX_RATE 0.28
using namespace std;
int main(){
   cout<< "Hi, today I am writing a program that analyses the product sales and inventory for a store.
    I will be using C++ to write this program. And I would also like to remid everyone that cpp is a compiled language.
    which means that the program is first converted to machine code or some kinda intermediate code before execution.
    that intermediate code will be stored as an executable and that executable can be run to get the desired output."<< endl;
    string productName;
    int soldQty,initialQty,newQty,category;
    double price;
    const double taxRate = 0.28;
    auto locationOfStore = "addis ababa";
    cout << "Enter the name of the product"<<endl;
    cin >> productName;
    cout <<"what is the category of "<< productName << endl;
    cin >> category;
    cout <<"what is the initial inventory quantity";
    cin >> initialQty;
    cout <<"what is its price?"<<endl;
    cin >> price;
    cout <<"what is the number of items sold?"<<endl;
    cin >> soldQty;
    decltype(TAX_RATE) totalSales = price * soldQty;
    string inventoryStatus = (newQty > 100) ? "In Stock" : "Low inventory";
    newQty = initialQty - soldQty;
    cout <<"current inventory is "<<newQty<<endl;
    switch(category){
        case 1:
            cout << "category 1: Laptops"<<endl;
            break;
        case 2:
            cout << "category 2: Phones"<<endl;
            break;        
        case 3:
            cout << "category 3: Food"<<endl;
            break;        
        case 4:
            cout << "category 4: Furniture"<<endl;
            break;        
        case 5:
            cout << "category 1: Stationery"<<endl;
            break;
    }
    int totalPrice;
    for(int i = 1; i <= soldQty; i++){
        totalPrice = soldQty*price;
        }
    cout << "total price is "<<totalPrice<<endl;    
    cout << "const tax rate is" << taxRate <<" preprocessor tax rate is "<<TAX_RATE<<endl;
    cout <<"inventory Status is"<<inventoryStatus<<endl;
    cout << "Helper Variables used "<<locationOfStore <<endl;
    cout <<"variables created with type deduction "<< totalSales <<" and "<< locationOfStore<< endl;
    return 0;
}