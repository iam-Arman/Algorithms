#include<bits/stdc++.h>
using namespace std;
// it is called tail recursion because it calls it self at the end of all operation 
void tail(int n)
{
    if(n>0)
    {
        cout<<n<<endl;
        return tail(n-1);
    }
}

int main()
{
    int n;
    n=5;
    tail(n);
}