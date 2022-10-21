#include<iostream>
using namespace std;

int fib(int n)
{
	if(n==0)
		return 0;
	if(n==1)
    	return 1;
	return(fib(n-1) + fib(n-2));

}


int fibsearch(int a[20],int key,int mid,int p,int q)
{
	int temp;
	if(key==a[mid])
	  return mid;

	if(key > a[mid])
	{
		if(p==1)
		    return -1;

		mid=mid+q;
		p=p-q;
		q=q-p;
		return(fibsearch(a,key,mid,p,q));

    }
	else
	{

		if(q==0)
		    return -1;

		mid=mid-q;
		temp=p-q;
		p=q;
		q=temp;

		return(fibsearch(a,key,mid,p,q));

	}
}

int linear(int a[20],int key,int n)
{
    int i=0;
    while(key!=a[i] && i<n)
      i++;
    if(i<n)
    	return i;
    else
    	return -1;

}

int sentinal(int a[20],int n,int key)
{
  int i;
  a[n]=key;
  i=0;
  while(a[i]!=key)
	  i++;
	  if(i!=n)

		  return i;
	  return -1;


}


int binary(int a[20],int key,int n)
{
    int l=0,h=n-1,mid,f=0;
    while(l<=h)
    {
    	mid=(l+h)/2;
    	if(key<=a[mid])
    	{
    		f=1;
    		break;
    	}
    	else
    	{
           if(key<a[mid])
        	   h=mid-1;
           else
              l=mid+1;
        }

    }
    if(f==1)
    	return mid;
    else
    	return -1;
}



int main()
{

	int a[20],key,n,k,p,q,mid,i,ch,r,x;
	cout<<"enter no. of elements in array";
	cin>>n;

	cout<<"enter array of integer values :";
	for(i=0;i<n;i++)
		cin>>a[i];

	cout<<"enter no. to search :";
	cin>>key;
	do{
	cout<<"MENU\n 1.linear search \n 2.sentinel search \n 3.fibonacci search \n 4.binary search\n ";
	cout<<"enter choice :";
	cin>>ch;
 switch(ch)
 {
 case 1:r=linear(a,key,n);
	     break;
 case 2:r=sentinal(a,n,key);
	     break;
 case 3:
	    for(k=1;fib(k)<=n;k++);
             p=fib(k-2);
             q=fib(k-3);
             mid=n-p+1;

            r=fibsearch(a,key,mid,p,q);
            break;

 case 4:r=binary(a,key,n);
          break;
 }
if(r==-1)
	cout<<"element not found!";
else
	 cout<<"key is found at "<<r+1<<" location in given array";
 cout<<"\n wants to continue?(1.yes/0.no)";
 cin>>x;

	}while(x==1);
}




/* OUTPUT
 enter no. of elements in array5
enter array of integer values :1 2 3 4 5
enter no. to search : 3
MENU
 1.linear search
 2.sentinal search
 3.fibonacci search
 4.binary search
 enter choice :1
key is found at 3 location in given array
 wants to continue?(1.yes/0.no)1
MENU
 1.linear search
 2.sentinal search
 3.fibonacci search
 4.binary search
 enter choice :2
key is found at 3 location in given array
 wants to continue?(1.yes/0.no)1
MENU
 1.linear search
 2.sentinal search
 3.fibonacci search
 4.binary search
 enter choice :3
key is found at 3 location in given array
 wants to continue?(1.yes/0.no)1
MENU
 1.linear search
 2.sentinal search
 3.fibonacci search
 4.binary search
 enter choice :4
key is found at 3 location in given array
 wants to continue?(1.yes/0.no)
 */
