#include<bits/stdc++.h>
using namespace std;
// it is called head recursion because it calls it self before any operation 
void head(int n)
{
    if(n>0)
    {
         head(n-1);
        cout<<n<<endl;
    }
}

int main()
{
    int n;
    n=5;
    head(5);
}