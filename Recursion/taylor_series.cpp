#include<bits/stdc++.h>
using namespace std;

#define ll long long 

ll taylor(int x,int n)
{
    static int p=1,f=1;

    int r;

    if(n==0)
     return 1;
    else
     {
        r=taylor(x,n-1);
        p=p*x;
        f=f*n;
        return r+p/f;
     }
}

int main()
{
    int x,n;
    cin>>x>>n;
    cout<<taylor(x,n)<<endl;
} 