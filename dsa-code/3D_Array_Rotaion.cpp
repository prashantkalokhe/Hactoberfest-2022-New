#include<iostream>
#include<vector>
using namespace std;
void rotate()
{
    long long int n,m,x,y,i,j,k;
    cout<<"Enter the value of n in 'n*n*n array': ";
    cin>>n;
    cout<<endl<<"Enter the number of rotations: ";
    cin>>x;
    cout<<endl;
    vector<std::vector<std::vector<int>>> v(n,std::vector<std::vector<int>>(n,std::vector<int> (n)));
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
                cin>>v[i][j][k];
    
    while(x--){
        int temp= 0;
        i=j=k=0;
        while(j<n){
            for(i=0;i<n;i++){
                temp+=v[i][j][i];
                v[i][j][i]=temp-v[i][j][i];
                temp-=v[i][j][i];
            }
            j++;
            if(j<n){
                for(i=n-1;i>=0;i--){
                temp+=v[i][j][i];
                v[i][j][i]=temp-v[i][j][i];
                temp-=v[i][j][i];
            }
            }
            j++;
        }
        v[0][0][0]=temp;
        i=j=k=0;
        while(j<n){
            for(i=0;i<n;i++){
                temp+=v[n-i-1][j][i];
                v[n-1-i][j][i]=temp-v[n-1-i][j][i];
                temp-=v[n-1-i][j][i];
            }
            j++;
            if(j<n){
                for(i=n-1;i>=0;i--){
                temp+=v[n-1-i][j][i];
                v[n-1-i][j][i]=temp-v[n-1-i][j][i];
                temp-=v[n-1-i][j][i];
            }
            }
            j++;
        }
        v[n-1][0][0]=temp;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                cout<<v[i][j][k]<<" ";
            }
            
        }
    }
}



int main()
{

int t=1;

int n=t;
    while(t--)
    {
        
        rotate();
        cout<<endl;
    }
return 0;
}
