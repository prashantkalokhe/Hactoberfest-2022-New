//in this algo we cnt no. of set bits in no.

// in this algo we and the no. n with n-1 till it becomes 0 and incease set cnt
/*the explanation to this would be when we subtract 1 from a no. the first bit from 
left which is set changes to 1 and all all right toi it which are 0 to 1
so by using this property we us this algo*/

#include <bits/stdc++.h>        //Theta(no. of set bits)
using namespace std;

int cntset(int n){
    int res=0;
    while(n>0){
        n=(n&(n-1));
        res++;
    }
    return res;
}


int main(){
    cout<<cntset(40)<<endl;
    return 0;
}