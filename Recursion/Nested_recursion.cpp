#include<bits/stdc++.h>
using namespace std;

// recursion inside the recursion

int fun(int n)
{
    if(n>100)
     return n-10;
    else 
     return fun(fun(n+11));

}

int main()
{
    int n;
    n=95;
    cout<<fun(n)<<endl;
}