#include<bits/stdc++.h>
using namespace std;
// we can find multiple missing elements in a sorted array between the starting and ending element 
// the time complexity is alomst O(n);
int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort(arr,arr+n);
    int diff=arr[0];

    for(int i=0;i<n;i++)
    {
       if(arr[i]-i!=diff)
       {
         while(arr[i]-i>diff)
         {
            cout<<diff+i<<" ";
            diff++;
         }
         diff=arr[i]-i;
       }
    }

    cout<<endl;

}