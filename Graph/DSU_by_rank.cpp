                                          //   Bismillahir Rahmanir Rahim      //
                                         //     After hardship comes ease     //
                                        //         AUTHOR : iamarman         //


#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds;

                                             ////       TEMPLATE       ////

//---------------------------------------------------------------------------------------------------------------------------------|

# define    el '\n'
# define    ff first
# define    ss second
# define    R0 return 0
# define    ll long long
# define    ull unsigned long long                                                                                                           
# define    rep(i,a,b) for(int i=a;i<b;i++)
# define    rep_n(i,a,b) for(int i=a;i<=b;i++)
# define    test int test; cin>>test; while(test--)
# define    rep_rev(i,a,b) for(int i=b;a>=1;i--)
# define    all(v) v.begin(),v.end()
# define    yess cout<<"YES"<<el
# define    sz(x) (int)x.size()
# define    noo cout<<"NO"<<el
# define    pb push_back
# define    mp make_pair
# define    sp " "


ll mod=1000000000+7;
ll INF=LLONG_MAX;
const double PI= acos(-1);
const double eps=1e-9;

# define mem(a,b) memset(a,b,sizeof(a))
# define sqr(a) ((a)*(a))
# define lcm(a,b) (a*b)/__gcd(a,b)

# define optimise   { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
# define fraction(a) cout.unsetf(ios::floatfield); cout.precision(a); cout.setf(ios::fixed,ios::floatfield);
# define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>


inline void file() {
 
#ifndef ONLINE_JUDGE
 
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
 
#endif // ONLINE_JUDGE

}

//----------------------------------------------------------------------------------------------------------------------------------|



                                                    ///  CODE STARTS FROM HERE    ///
  

class DSU{
    vector<int> parent,rank;
public:
    DSU(int n)
    {
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }

    int findUparent(int node)
    {
        if(node==parent[node])
        {
            return node;
        }

        return parent[node]=findUparent(parent[node]);
    }

    void unionByrank(int u,int v)
    {
        int ulpar_u=findUparent(u);
        int ulpar_v=findUparent(v);

        if(ulpar_u==ulpar_v)
        {
            return;
        }
        if(rank[ulpar_v]==rank[ulpar_u])
        {
            parent[ulpar_v]=ulpar_u;
            rank[ulpar_u]++;
        }
        else if(rank[ulpar_u]>rank[ulpar_v])
        {
            parent[ulpar_v]=ulpar_u;

        }
        else
        {
            parent[ulpar_u]=ulpar_v;
        }
    }

};
void solve()
{
   int n,m;
   cin>>n>>m;
   DSU dsu(n);

   for(int i=0;i<m;i++)
   {
    int u,v;
    cin>>u>>v;
    dsu.unionByrank(u,v);
   }

   int q;
   cin>>q;
   while(q--)
   {
     int x,y;
     cin>>x>>y;
     if(dsu.findUparent(x)==dsu.findUparent(y))
     {
       cout<<"yes"<<el;
     }
     else cout<<"no"<<el;
   }


 

}

int main()
{
    optimise;
    file();
 
    clock_t q= clock();

   // test
    { 
      solve();
    }
 
    cerr << "Run Time : " <<((double)(clock() - q) / CLOCKS_PER_SEC)<<el;
  
}
