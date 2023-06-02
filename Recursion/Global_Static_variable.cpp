#include<bits/stdc++.h>
using namespace std;

int fun_sta(int n)
{
    static int x=0;
    if(n>0)
    {
        x++;
        return fun_sta(n-1)+x;
    }
    return 0;
}

int y=0;
int fun_glo(int n)
{
    if(n>0)
    {
        y++;
        return fun_glo(n-1)+y;
    }
    return 0;
}

int main()
{
    int p=5;

    cout<<fun_sta(p)<<endl;

    cout<<fun_glo(p)<<endl;
}