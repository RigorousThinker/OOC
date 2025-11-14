#include<iostream>
using namespace std;
class student
{
private:
int rn;
char name[10];
public:
void display()
{
cout<<"Enter roll no."<<endl;
cin>>rn;
cout<<"Enter student name"<<endl;
cin>>name;
}
};

int main()
{
student stu_obj,stu_obj1;
 stu_obj.display();
stu_obj1.display();
return 0;
}
