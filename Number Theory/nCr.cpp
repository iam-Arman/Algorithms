#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

ll bigmod(ll base,ll power)
{ 
    ll res=1;
    ll p=base%mod; 
    while(power>0)
    { 
        if(power%2==1)
        {  
            res=((res%mod)*(p%mod))%mod; 
        }  
        power/=2; 
        p=((p%mod)*(p%mod))%mod; 
    }
    return res;
}

ll inversemod(ll base) 
{ 
    return bigmod(base,mod-2); 
}

long long fact[N];

void factorial()
{
    fact[0] = 1;
    for(int i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
    }
}

ll ncr(int n,int r)
{
    if(r>n) return 0;

    ll ans=fact[n];
    ll din=fact[r]*fact[n-r];
    ans*=inversemod(din);
    ans%=mod;

    return ans;
}

int main()
{
    factorial();

    int n,r;
    cin>>n>>r;

    cout<<ncr(n,r)<<endl;
}

