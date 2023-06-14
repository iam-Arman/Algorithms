#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main()
{
    int arr[]={1,4,6,2,5,3,8,7};
    bubble_sort(arr,8);
    for(int i=0;i<8;i++)
    {
        cout<<arr[i]<<' ';

    }
    cout<<endl;
}
