#include<iostream>
using namespace std;
class complex{
float real,img;
public:
void input(){
cout<<"Enter real part:";
cin>>real;
cout<<"Enter imaginry part:";
cin>>img;
}
complex add(complex c){
complex temp;
temp.real= real +c.real;
temp.img=img +c.img;
return temp;
}
void display(){
if(img>=0)
   cout<<real<<"+"<<img<<"i"<<endl;
      else
       cout<<real<<"-"<<-img<<"i"<<endl;
}
};
  int main() {
complex c1,c2,result;
cout<<"Enter first complex number:\n";
c1.input();
cout<<"Enter second complex number:\n";
c2.input();
result=c1.add(c2);
cout<<"\n Sum of two complex numbers=";
result.display();
return 0;
}

 
