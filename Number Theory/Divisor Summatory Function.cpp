#include<bits/stdc++.h>
using namespace std;
using ll =long long;

// this code finds the sum of number of divisors from 1 to n in sqrt(n) time
int main()
{
    ll n;
    cin>>n;

    int sq=sqrt(n);
    ll ans=0;
    for(int i=1;i<=sq;i++)
    {
        ans+=(n/i)-i;
    }
    ans*=2;
    ans+=sq;

    cout<<ans<<endl;
}
