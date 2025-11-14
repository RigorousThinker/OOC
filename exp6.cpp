#include<iostream>
#include<stdio.h>
using namespace std;
class Student
{
int roll;
char name[25];
public:
void getdata()
{
cout<<"\n--------------------------";
cout<<"\n Enter Roll No:";
cin>>roll;
cout<<"\n Enter Student Name:";
cin>>name;
}
void putdata()
{
cout<<"\n----------------------------- ";
cout<<"\n *************Student Marklist***************";
cout<<"\n --------------------------";
cout<<"\n Roll No. :"<<roll;
cout<<"\n Student Name:"<<name<<endl;
}
};
class StudentExam:public Student //Class StudentExam derived from class student
{
public:
int sub1,sub2,sub3,sub4,sub5,sub6;
float Per;
public:
void accept_data()
{
getdata();
cout<<"\n Enter Marks for subject1:";
cin>>sub1;
cout<<"\n Enter Marks for subject2";
cin>>sub2;
cout<<"\n Enter Marks for subject3";
cin>>sub3;
cout<<"\n Enter Marks for subject4:";
cin>>sub4;
cout<<"\nEnter Marks for subject5";
cin>>sub5;
cout<<"\n Enter Marks for subject6:";
cin>>sub6;
}
void display_data()
{
putdata();
cout<<"\nMarks of subject1:"<<sub1;
cout<<"\nMarks of subject2:"<<sub2;
cout<<"\nMarks of subject3:"<<sub3;
cout<<"\nMarks of subject4:"<<sub4;
cout<<"\nMarks of subject5:"<<sub5;
cout<<"\nMarks of subject6:"<<sub6;
}
};
class StudentResult:public StudentExam //Class StudentResult derived from class StudentExam
{
public:
void calculate()
{
Per=(sub1+sub2+sub3+sub4+sub5+sub6)/6.0;
cout<<"\n\n Total Percentage:"<<Per;
cout<<"\n-------------------------\n";
}
};
int main()
{
StudentResult str;
int cnt, i;
cout<<"\n Enter No.of students You Want?:";
cin>>cnt;
for(i=0;i<cnt;i++)
{
str.accept_data();
str.display_data();
str.calculate();
}
return 0;
}






