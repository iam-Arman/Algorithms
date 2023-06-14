#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int mn=INT_MAX;
        int x=-1;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<mn)
            {
                mn=arr[j];
                x=j;
            }
        }
       if(x!=-1) swap(arr[i],arr[x]);
    }
}

int main()
{
    int arr[]={1,4,2,5,6,7,3,2};
    selection_sort(arr,8);

    for(int i=0;i<8;i++)
    {
        cout<<arr[i]<<' ';
    }

    cout<<endl;

}
