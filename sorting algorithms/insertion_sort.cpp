#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int x=arr[i];
        while(j>=0 and arr[j]>x)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=x;
    }
}
int main()
{
    int arr[]={1,4,2,5,6,7,3,2};
    insertion_sort(arr,8);

    for(int i=0;i<8;i++)
    {
        cout<<arr[i]<<' ';
    }

    cout<<endl;

}
