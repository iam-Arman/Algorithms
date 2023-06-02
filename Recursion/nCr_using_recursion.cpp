#include<bits/stdc++.h>
using namespace std;
// this fomular works on pascal triangle ncr=(n-1)c(r-1)+(n-1)cr
int c(int n,int r)
{
    if(r==0 or n==r)
    {
        return 1;
    }

    return c(n-1,r-1)+c(n-1,r);
}

int main()
{
    int n,r;
    cin>>n>>r;

    cout<<c(n,r)<<endl;
}