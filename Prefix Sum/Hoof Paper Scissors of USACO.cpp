#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);

    int n,pc,hc,sc;
    cin>>n;

    char c;
    int h[n+6],p[n+6],s[n+6],ans[4];
    for(int i=0;i<n;i++){
        cin>>c;
        if(c=='H')
        {
            h[i]=1;
            p[i]=0;
            s[i]=0;
        }
        else if(c=='S')
        {
            h[i]=0;
            p[i]=0;
            s[i]=1;
        }
        else if(c=='P')
        {
            h[i]=0;
            p[i]=1;
            s[i]=0;
        }
    }
    for(int i=1;i<n;i++)
    {
            h[i]+=h[i-1];
            p[i]+=p[i-1];
            s[i]+=s[i-1];
    }

    //for(int i=0;i<n;i++)cout<<p[i]<<' ';cout<<endl;
    //for(int i=0;i<n;i++)cout<<h[i]<<' ';cout<<endl;
    //for(int i=0;i<n;i++)cout<<s[i]<<' ';cout<<endl;


    pc=p[n-1];
    hc=h[n-1];
    sc=s[n-1];

    int l,r,mx=-1;

        //cout<<"P and H"<<endl;
        for(int i=0;i<n;i++)
        {
            l=p[i];
            r=h[n-1]-h[i];
            mx=max(mx,l+r);
          //  cout<<i<<' '<<l<<' '<<r<<endl;
        }
        //cout<<"P and S"<<endl;
        for(int i=0;i<n;i++)
        {
            l=p[i];
            r=s[n-1]-s[i];
            mx=max(mx,l+r);
          //  cout<<i<<' '<<l<<' '<<r<<endl;
        }

        //cout<<"P and H"<<endl;
        for(int i=0;i<n;i++)
        {
            l=h[i];
            r=p[n-1]-p[i];
            mx=max(mx,l+r);
          //  cout<<i<<' '<<l<<' '<<r<<endl;
        }
        //cout<<"P and S"<<endl;
        for(int i=0;i<n;i++)
        {
            l=h[i];
            r=s[n-1]-s[i];
            mx=max(mx,l+r);
            //cout<<i<<' '<<l<<' '<<r<<endl;
        }

        for(int i=0;i<n;i++)
        {
            l=s[i];
            r=h[n-1]-h[i];
            mx=max(mx,l+r);
        }
        for(int i=0;i<n;i++)
        {
            l=s[i];
            r=p[n-1]-p[i];
            mx=max(mx,l+r);
        }

    cout<<mx<<endl;
//main();
}
