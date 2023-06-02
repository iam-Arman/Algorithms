#include<bits/stdc++.h>
using namespace std;

// it is called tree recursion because it call itself more than once 
void tree(int n)
{
    if(n<=0) return;
    cout<<n<<endl;
    
    tree(n-1);
    tree(n-1);

}

int main()
{
    int n=3;
    tree(3);
}