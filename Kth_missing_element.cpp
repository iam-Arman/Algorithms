#include<bits/stdc++.h>
using namespace std;
// this in a way to find kth missing element is a sorted array 
// time complexity is O(n);
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> vec(n);
    
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }

    int cnt=vec[0]-1;
    if(k>vec[n-1])
    {
        cout<<vec[n-1]+k<<endl;
        return 0;
    }
    if(k<vec[0])
    {
        cout<<k<<endl;
    }

    int ans=0;
    int diff=vec[0];
    bool ok=false;

    for(int i=0;i<n;i++)
    {
        if(vec[i]-i!=diff)
        {
            while(vec[i]-i>diff)
            {
                ans=diff+i;
                cnt++;
                diff++;
                if(k==cnt)
                {
                    ok=true;
                    break;
                }
            }
            diff=vec[i]-i;
        }
        if(ok) break;
    }

    if(cnt!=k) ans=vec[n-1]+(k-cnt);

    cout<<ans<<endl;




}