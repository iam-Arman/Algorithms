#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int l,int mid,int h)
{
    int i=l,j=mid+1,k=l;
    int b[10000];
    
    while(i<=mid and j<=h)
    {
        if(arr[i]<arr[j])
        {
            b[k]=arr[i];
            k++;
            i++;
        }
        else
        {
            b[k]=arr[j];
            k++;
            j++;
        }
        
    }

        for(;i<=mid;i++)
        {
            b[k]=arr[i];
            k++;
        }
        for(;j<=h;j++)
        {
            b[k]=arr[j];
            k++;
        }

        for(int i=l;i<=h;i++)
        {
            arr[i]=b[i];
        }

   
}

void merge_sort(int arr[],int l,int h)
{
    int mid;
    if(l<h)
    {
        mid=(l+h)/2;

        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}

int main()
{
    int arr[]={3,4,2,2,1,5,7,8};


    merge_sort(arr,0,7);

    for(int i=0;i<8;i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;


}
