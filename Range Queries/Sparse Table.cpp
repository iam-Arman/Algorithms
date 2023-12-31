#include<bits/stdc++.h>
using namespace std;

class SparseTable
{
    public:
    vector<vector<int> > st;

    SparseTable(int n,vector<int> &vec)
    {
        st.resize(n+2,vector<int> (__lg(n)+2));

        for(int i=0;i<n;i++)  // 0 based for 1 based do i=1 to n
        {
            st[i][0]=vec[i];
        }

        int k=__lg(n)+1;

        for(int j=1;j<=k;j++)
        {
            for(int i=0;i+(1<<j)<=n;i++) // 0 based for 1 based do i=1 to n+1
            {
                st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);  // instead of min we can use max , gcd, lcm , or , and 
            }
        }

    }

    int query(int l,int r)
    {
        int j=__lg(r-l+1);
        return min(st[l][j],st[r-(1<<j)+1][j]);
    }

    int query1(int l,int r) // query in logn for non idempotent function
    {
        int ans=INT_MAX;
        for(int j=__lg(r-l+1);j>=0;j--) 
        {
            if((1<<j)<=(r-l+1))
            {
                ans=min(ans,st[l][j]);
                l+=(1<<j);
            }
        }
        return ans;
    }

    
};


int main()
{
     int n;
     cin>>n;
     
     vector<int> vec(n);
     for(int i=0;i<n;i++) cin>>vec[i];

     SparseTable st(n,vec);

     int q;
     cin>>q;

     while(q--)
     {
         int l,r;
         cin>>l>>r;
         cout<<st.query(l,r)<<endl;
     }

     
}
