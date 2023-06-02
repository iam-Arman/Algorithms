#include<bits/stdc++.h>
using namespace std;

int ackerman(int m,int n)
{
    if(m==0 ) return n+1;
    if(n==0 and m!=0) return ackerman(m-1,1);
    return ackerman(m-1,ackerman(m,n-1));
}

int main()
{
    int a,b;
    cin>>a>>b;
    int ans=ackerman(a,b);
    cout<<ans<<endl;
}