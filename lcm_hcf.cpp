#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int hcf(int a, int b){
    int temp;
    while(b!=0)
        {
                temp=b;
                b=a%b;
                a=temp;
        }
        return a;
}
int lcm(int a, int b){
    int temp;
    int mul=a*b;
    while(b!=0)
        {
                temp=b;
                b=a%b;
                a=temp;
        }
        return mul/a;
}

int main(){
cout<<"enter any two positive non zero number\n";
int n,m;
cin>>n>>m;
cout<<"Lcm: "<<lcm(n, m)<<"\nHcf: "<<hcf(n, m);
  return 0;
}