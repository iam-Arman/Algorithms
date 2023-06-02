#include<bits/stdc++.h>
using namespace std;
// this will first print and then call it self so output will be 3 2 1 like that first it will print then it will go to next level then after going next level it will first print then go to next level

void recursion1(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        recursion1(n-1);
    }
}
// this will first complete all the call and then returning time print 1 2 3 because it will call it self untill n is greater then zero then before ruturning to previous function it will first print then go to the previous funtion call
void recursion2(int n)
{
    if(n>0)
    {
        recursion2( n-1);
        cout<<n<<" ";
    }
}

int main()
{
    int n=3;
    recursion1(3);
    cout<<endl;
    recursion2(3);
    cout<<endl;
}