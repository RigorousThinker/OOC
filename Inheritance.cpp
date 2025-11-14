#include <iostream>
using namespace std;
class Vehicle
{
public:
string brand;
Vehicle() { brand = "Ford";}
void honk()
{
cout<<"Hi Hello"<<endl;
}
};
class Car: public Vehicle
{
public:
string model;
Car() { model = "BMW";}
};
int main()
{
Car mycar;
mycar.honk();
cout<< mycar.brand<<" "<<mycar.model;
return 0;
}
