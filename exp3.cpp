#include<iostream>
using namespace std;
//saving Account class
class SavingAccount {
private:
string accountHolderName;
int accountNumber;
double balance;
double interestRate;
public:
SavingAccount(string name,int accNumber,double initialBalance,double rate){
accountHolderName=name;
accountNumber=accNumber;
balance=initialBalance;
interestRate=rate;
}
void deposit(double amount){
if(amount>0){
balance+=amount;
cout<<"Deposited:"<<amount<<endl;
}
}
void withdraw(double amount){
if(amount>0 && amount<=balance){
balance=amount;
cout<<"Withdrawn:"<<amount<<endl;
}else{
cout<<"insufficient balance!"<<endl;
}
}
void applyInterest(){
double interst= balance*interstRate/100;
balance+=interest;
cout<<"Interst Applied:"<<interest<<endl;
}
void display(){
cout<<"\n[Savings Account]"<<endl;
cout<<"Account Holder:"<<accountHolderName<<endl;
cout<<"Account Number:"<<accountNumber<<endl;
cout<<"Balance:"<<balance<<endl;
cout<<"Interst Rate:"<<interestRate<<"%"<<endl;
}
};
//Checking Account Class
class CheckingAccount{
private:
string accountHolderName;
int accountNumber;
double balance;
double transactionFee;
public:
CheckingAccount(string name,int accNumber,double initialBalance,double fee){
acccount HolderName=name;
accountNumber=accNumber;
balance=initialBalance;
transactionFee=fee;
}
void deposit(double amount){
if(amount>0){
balance+=amount;
cout<<"Deposited:"<<amount<<endl;
}
}
void withdraw(double amount){
double total=amount+transactionFee;
if(total<=balance){
balance=total;
cout<<"Withdrawn:"<<amount<<"(<<transactionFee<<"fee applied)"<<endl;
}else{
cout<<"Insufficient balance for withdrawl+fee!"<<endl;
}
}
void display(){
cout<<"\n[Checking Account]"<<endl;
cout<<"Account Holder:"<<accountHolderName<<endl;
cout<<"Account Number:"<<accountNumber<<endl;
cout<<"Balance:"<<balance<<endl;
cout<<"Transaction Fee:"<<transactionFee<<endl;
}
};
int main(){
SavingAccount savings("Alice",1001,5000.0,3.0);
CheckingAccount checking("Bob",1002,3000.0,20.0);
savings.display();
savings.deposit(1000);
savings.withdraw(2000);
savings.applyInterest();
savings.display();
checking.display();
checking.deposit(1500);
checking.withdraw(1000);
checking.display();
return 0;
}
