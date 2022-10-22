#include <bits/stdc++.h>
using namespace std;
class bank
{
private:
    string password="abtparcelservice";
    int balance=70000;
public:
    //int balance=70000;
    int password_check()
   {
      string password_1,name;
      cout<<"________________________Welcome to ABN Bank________________________";
      cout<<"\nEnter Name: ";
      cin>>name;
      cout<<"Enter password: ";
      cin>>password_1;
      if(password==password_1)
      {
          mainframe();
      }
      else
      {
          cout<<"Wrong password!";
      }
   }
   void mainframe()
   {
       int choice,option;
       do{
           cout<<"\n                        MENU                         ";
           cout<<"\n1.Check Balance\n2.Deposit Cash\n3.Withdraw Cash\n4.Change Password";
           cout<<"\nSelect option: ";
           cin>>choice;
           switch(choice)
           {
               case 1: check_balance();
                       break;
               case 2: deposit_cash();
                       break;
               case 3: withdraw_cash();
                       break;
               case 4: change_password();
                       break;
              default: cout<<"Incorrect option!";
                        break;
           }
           cout<<"\nDo you wish to continue?(0/1): ";
           cin>>option;
       }while(option);
  }
       int check_balance()
       {
           cout<<"The balance is: "<<balance;
       }
       int deposit_cash()
       {
           int deposit;
           cout<<"Enter amount: ";
           cin>>deposit;
           balance=balance+deposit;
           cout<<"Updated balance: "<<balance;
        }
       int withdraw_cash()
       {
           int withdraw;
           cout<<"Enter amount: ";
           cin>>withdraw;
           if(balance>=withdraw)
           {balance=balance-withdraw;}
           else
           {
               cout<<"Insufficient balance!!!";
           }
           cout<<"Updated Balance: "<<balance;
       }
       int change_password()
       {
           string new_password,old_password;
           cout<<"Enter existing password: ";
           cin>>old_password;
           if(old_password==password)
           {
               cout<<"\nEnter new password: ";
               cin>>new_password;
               password=new_password;
           }
           else{
            cout<<"Incorrect password!";
           }
   }
};

int main()
{
    bank obj;
    obj.password_check();
    return 0;
}
