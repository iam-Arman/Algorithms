#include<bits/stdc++.h>
using namespace std;

#define ll long long 

ll pow(ll base,ll power)
{ 
    if(power==0) return 1;
    if(power%2==0)
     return pow(base*base,power/2);
    else 
     return base*pow(base*base,power/2);
}

int main()
{
    int base,power;
    cin>>base>>power;
    
    cout<<pow(base,power)<<endl;
}