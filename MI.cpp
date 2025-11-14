#include<iostream>
using namespace std;
class Vehicle{
public:
Vehicle()
{
cout<<"This is a Vehicle \n";
}
};
class fourwheeler:public Vehicle{
public:
fourwheeler()
{
cout<<"This Vehicle is 4 wheeler \n";
}
};
class Car:public Vehicle,public fourwheeler{
public:
Car()
{
cout<<"This 4 wheeler is a Car\n";
}
};
int main()
{
Car obj;
return 0;
}
