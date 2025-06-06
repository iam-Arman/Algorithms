#include<bits/stdc++.h>
using namespace std;

template <typename T>
class SparseTable
{
    public:
    vector<vector<T> > st;

    T op(T a,T b)
    {
        return __gcd(a,b);
    }

    SparseTable(int n,vector<T> &vec)
    {
        st.resize(n+2,vector<T> (__lg(n)+2));

        for(int i=1;i<=n;i++)  
        {
            st[i][0]=vec[i];
        }

        int k=__lg(n)+1;

        for(int j=1;j<=k;j++)
        {
            for(int i=1;i+(1<<j)<=n+1;i++) 
            {
                st[i][j]=op(st[i][j-1],st[i+(1<<(j-1))][j-1]); 
            }
        }

    }

    T query(int l,int r)
    {
        int j=__lg(r-l+1);
        return op(st[l][j],st[r-(1<<j)+1][j]);
    }

    T query1(int l,int r) // query in logn for non idempotent function
    {
        int ans=0;
        for(int j=__lg(r-l+1);j>=0;j--) 
        {
            if((1<<j)<=(r-l+1))
            {
                ans=op(ans,st[l][j]);
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

     SparseTable<ll> st(n,vec);

     int q;
     cin>>q;

     while(q--)
     {
         int l,r;
         cin>>l>>r;
         cout<<st.query(l,r)<<endl;
     }

     
}
