                                                  //   Bismillahir Rahmanir Rahim      //
                                                 //     After hardship comes ease     //
                                                //         AUTHOR : iamarman         //

// pragmas
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("unroll-loops")
// #pragma GCC optimization ("strict-overflow")
 
#include<bits/stdc++.h>


using namespace std;

#ifndef __clang__
    #include <ext/pb_ds/tree_policy.hpp>
    #include <ext/pb_ds/assoc_container.hpp>
    using namespace __gnu_pbds;
#endif

                                                    ////       TEMPLATE       ////

//---------------------------------------------------------------------------------------------------------------------------------|


# define    el '\n'
# define    sp " "
# define    ff first
# define    ss second
# define    ll long long
# define    pb push_back
# define    mp make_pair
# define    yess1 cout<<1<<el 
# define    noo cout<<"NO"<<el
# define    yess cout<<"YES"<<el
# define    siz(x) (int)x.size()
# define    ull unsigned long long    
# define    all(v) v.begin(),v.end()
# define    allr(v) v.rbegin(),v.rend()
# define    torad(x) ((x) * ((2*acos(0))/180.0))
# define    todeg(x) ((x) * (180.0/(2*acos(0))))

constexpr ll mod=1000000000+7;
constexpr ll INF=LLONG_MAX;
constexpr double PI= acos(-1);
constexpr double eps=1e-9;

# define mem(a,b) memset(a,b,sizeof(a))
# define sqr(a) ((a)*(a))
# define lcm(a,b) (a*b)/__gcd(a,b)

# define optimise   { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
# define fraction(a) cout.unsetf(ios::floatfield); cout.precision(a); cout.setf(ios::fixed,ios::floatfield);
# define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>

// find_by_order() - Returns an iterator to the k-th largest element (counting from zero)
// order_of_key()  - The number of items in a set that are strictly smaller than our item 
// greater instead of less for descending order
// less_equal works as ordered multiset
// we can use pair<int,int> instead of int for pair of orderd set
// for multiset st.lower_bound(x) works as upper bound and st.upper_bound(x) works as lower bound

inline void file() {
#ifndef ONLINE_JUDGE  
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}
//----------------------------------------------------------------------------------------------------------------------------------|


                                                               // DEBUGGER //


//----------------------------------------------------------------------------------------------------------------------------------|

template < typename F, typename S > ostream& operator << ( ostream& os, const pair< F, S > & p ) { return os << "(" << p.first << ", " << p.second << ")"; }
template < typename T > ostream &operator << ( ostream & os, const vector< T > &v ) { os << "{"; for(auto it = v.begin(); it != v.end(); ++it) { if( it != v.begin() ) os << ", ";  os << *it; }  return os << "}";  }
template < typename T >  ostream &operator << ( ostream & os, const set< T > &v ) { os << "["; for(auto it = v.begin(); it != v.end(); ++it) { if( it != v.begin() ) os << ", "; os << *it;  } return os << "]"; }
template < typename T > ostream &operator << ( ostream & os, const multiset< T > &v ) { os << "["; for(auto it = v.begin(); it != v.end(); ++it) { if( it != v.begin() ) os << ", "; os << *it; } return os << "]"; }
template < typename F, typename S > ostream &operator << ( ostream & os, const map< F, S > &v ) { os << "["; for(auto it = v.begin(); it != v.end(); ++it) { if( it != v.begin() ) os << ", "; os << it -> first << " = " << it -> second ; } return os << "]";  }
#define dbg(args...) do {cerr << #args << " : "; iamarman(args); } while(0)
void iamarman () { cerr << endl; }
template <typename T> void iamarman( T a[], int n ) {   for(int i = 0; i < n; ++i) cerr << a[i] << ' '; cerr << endl;  }
template <typename T, typename ... hello>  void iamarman( T arg, const hello &... rest) {   cerr << arg << ' ';  iamarman(rest...);  }

//--------------------------------------------------------------------------------------------------------------------------------------|



                                                           /////    FUNCTIONS     /////



ll bigmod(ll base,ll power){ ll res=1; ll p=base%mod; while(power>0) { if(power%2==1) {  res=((res%mod)*(p%mod))%mod; }  power/=2; p=((p%mod)*(p%mod))%mod; } return res; }

ll inversemod(ll base) { return bigmod(base,mod-2); }

ll poww(ull a,ull b) { ull ans=1; if(!b) return 1; while(b>1) {  if(b&1) { ans=ans*a%mod; } a=a*a%mod; b/=2; }return a*ans%mod; }

int gcd(ll a,ll b) { ll rem; while(b%a!=0)  {  rem=b%a;  b=a;  a=rem; } return a; }

ll sqrtt(ll a){ long long x = sqrt(a) + 2; while (x * x > a) x--; return x;}

ll sqrt(ll n) {ll low=0,high=1e10; while(high-low>1){ ll mid=low+(high-low)/2; if(mid*mid<=n) low=mid; else high=mid; }return low; }

long double sqrtd(long double n){ long double low=0,high=n,mid; for(int i=0;i<100;i++) { mid=(low+high)/2; if(mid*mid<=n) low=mid; else high=mid;} return low;}

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

inline ll getrandom(ll a,ll b) { return uniform_int_distribution<ll>(a,b)(rng); }

 
int dx[]={-1, 1 , 0 , 0 , -1 ,-1, 1, 1};
int dy[]={ 0, 0 ,-1 , 1 , -1 , 1,-1, 1};

// up = { -1,0 } , down = { 1,0 } , right = { 0,1 } , left = { 0,-1 }
// up-right = { -1,1 } , up-left = { -1,-1 } , down-right = { 1,1 } , down-left = { 1,-1 }




                                                   ///  ____________CODE STARTS FROM HERE____________    ///



int LOG;
vector<vector<int> > ancestor;
vector<int> depth;
int kth(int node,int k)
{
    for(int i=0;i<LOG;i++)
    {
        if((1<<i)&k)
        {
            node=ancestor[node][i];
        }
    }
    return node;
};

int lca(int u,int v)
{
    if(depth[u]<depth[v]) swap(u,v);
    u=kth(u,depth[u]-depth[v]);
    if(u==v) return u;
    for(int i=LOG-1;i>=0;i--)
    {
        if(ancestor[u][i]!=ancestor[v][i])
        {
            u=ancestor[u][i];
            v=ancestor[v][i];
        }
    }
    return ancestor[u][0];
};

int dist(int u, int v)
{
    return depth[u]+depth[v]-2*depth[lca(u,v)];
}

class DSU{
public:
    vector<int> parent,size,endA,endB;
    vector<int> diam;
    int globalMax;
    DSU(int n)
    {
        parent.resize(n+5,0);
        size.resize(n+5,1);
        endA.resize(n+5,0);
        endB.resize(n+5,0);
        diam.resize(n+5,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            endA[i] = i;
            endB[i] = i;
        }
        globalMax=0;
    }

    int findUpar(int node)
    {
        if(node==parent[node]) return node;
        return parent[node]=findUpar(parent[node]);
    }

    void unionBysize(int u, int v) {
        int rootU = findUpar(u);
        int rootV = findUpar(v);

        if (rootU == rootV) return;
        if (size[rootU] < size[rootV]) swap(rootU, rootV);

        int u1=endA[rootU];
        int v1=endB[rootU];
        int u2=endA[rootV];
        int v2=endB[rootV];

        if(diam[rootV]>diam[rootU])
        {
            diam[rootU]=diam[rootV];
            endA[rootU]=u2;
            endB[rootU]=v2;
            globalMax=max(globalMax,diam[rootU]);
        }

        int dis=dist(u1,u2);
        if(dis>diam[rootU])
        {
            diam[rootU]=dis;
            endA[rootU]=u1;
            endB[rootU]=u2;
            globalMax = max(globalMax,diam[rootU]);
        }
        
        dis=dist(u1,v2);
        if(dis>diam[rootU])
        {
            diam[rootU]=dis;
            endA[rootU]=u1;
            endB[rootU]=v2;
            globalMax = max(globalMax,diam[rootU]);
        }
        dis=dist(v1,u2);
        if(dis>diam[rootU])
        {
            diam[rootU]=dis;
            endA[rootU]=v1;
            endB[rootU]=u2;
             globalMax = max(globalMax,diam[rootU]);
        }
        dis=dist(v1,v2);
        if(dis>diam[rootU])
        {
            diam[rootU]=dis;
            endA[rootU]=v1;
            endB[rootU]=v2;
            globalMax=max(globalMax,diam[rootU]);
        }

        parent[rootV]=rootU;
        size[rootU]+=size[rootV];
    }

    int get()
    {
        return globalMax;
    }
};

void solve()
{  
    int n;
    cin>>n;
    vector<vector<int> > graph(n+1);
    vector<pair<int,int> > edges;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
        edges.pb({u,v});
    }

   
    LOG = 1;
    while((1<<LOG)<=n) ++LOG;
    depth.assign(n+1,0);
    ancestor.assign(n+1,vector<int>(LOG+1,0));
    auto rec=[&](auto&& self,int node,int par)->void
    {
        if(par!=0) depth[node]=depth[par]+1;
        ancestor[node][0]=par;
        for(int i=1;i<LOG;i++)
        {
            int prev=ancestor[node][i-1];
            ancestor[node][i]=ancestor[prev][i-1];
        }
        for(auto it : graph[node])
        {
            if(it==par) continue;
            self(self,it,node);
        }
    };
    rec(rec,1,0);

    DSU ds(n);
    vector<int> ans(n+1);
    for(int i=n-1;i>=1;i--)
    {
        ds.unionBysize(edges[i-1].ff,edges[i-1].ss);
        ans[i]=ds.get();
    }

    for(int i=2;i<=n;i++)
    {
        cout<<ans[i]<<sp;
    }
    cout<<el;


}

int main()
{ 
    optimise;
    #ifdef LOCAL
        auto start = chrono::high_resolution_clock::now();
    #endif
    
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++)
    {
		#ifdef LOCAL
            cout <<"\tTest case " << i << endl;
        #endif
        
        solve();
    }
    #ifdef LOCAL
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cerr << "Time taken: " << duration.count() / 1000.0 << " ms" << endl;
    #endif
  
}


