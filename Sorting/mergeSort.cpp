#include <bits/stdc++.h>
using namespace std;

void Merge(int A[],int l,int mid,int h){
	int i,j,k;
	i=l;
	j=mid+1;
	k=l;
	int B[100];
	while(i<mid+1&&j<=h){
		if(A[i]<A[j]){
			B[k++]=A[i++];
		}
		else{
			B[k++]=A[j++];
		}
	}
	for(i;i<mid+1;i++){
		B[k++]=A[i];
	}
	for(j;j<=h;j++){
		B[k++]=A[j];
	}
	for(int i=l;i<=h;i++){
		A[i]=B[i];
	}


}
void MergeSort(int A[],int l,int h){
	if(l<h){
		int mid=(l+h)/2;
		MergeSort(A,l,mid);
		MergeSort(A,mid+1,h);
		Merge(A,l,mid,h);
	}
}
int main(){
	int A[5]={32,54,12,98,21};
	MergeSort(A,0,4);
    for(int i=0;i<5;i++){
    	cout<<A[i]<<" ";
    }




return 0;    
}+
