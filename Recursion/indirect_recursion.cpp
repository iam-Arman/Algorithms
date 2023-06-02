#include<bits/stdc++.h>
using namespace std;

// it is called indirect because a function doesn't calls it self it calls another function a that function calls that function

void funB(int n);

void funA(int n)
{
    if(n<=0) return;
    cout<<n<<endl;
    funB(n-1);


}

void funB(int n)
{
    if(n<=1) return;
    cout<<n<<endl;
    funA(n/2);
}

int main()
{
    int n;
    n=10;
    funA(10);

}