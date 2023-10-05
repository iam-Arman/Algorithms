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

typedef     vector<int> vii;
typedef     vector<long long> vll;
typedef     vector<pair<int,int> > vpi;
typedef     vector<pair<long long,long long > > vpl;

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

// find_by_order() - Returns an iterator to the k-th largest element (counting from zero)
// order_of_key()  - The number of items in a set that are strictly smaller than our item 
// greater instead of less for descending order
// less_equal works as ordered multiset
// we can use pair<int,int> instead of int for pair of orderd set
// for multiset st.lower_bound(x) works as upper bound and st.upper_bound(x) works as lower bound


typedef vector<int>::iterator vit;
typedef vector<ll>::iterator vlt;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;


inline void file() {
 
#ifndef ONLINE_JUDGE
 
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
 
#endif // ONLINE_JUDGE

}

//----------------------------------------------------------------------------------------------------------------------------------|



                                                   // DEBUGGER //


//-----------------------------------------------------------------------------------------------------------------------------------|

template < typename F, typename S > ostream& operator << ( ostream& os, const pair< F, S > & p ) { return os << "(" << p.first << ", " << p.second << ")"; }
 
template < typename T > ostream &operator << ( ostream & os, const vector< T > &v ) { os << "{"; for(auto it = v.begin(); it != v.end(); ++it) { if( it != v.begin() ) os << ", ";  os << *it; }  return os << "}";  }
 
template < typename T >  ostream &operator << ( ostream & os, const set< T > &v ) { os << "["; for(auto it = v.begin(); it != v.end(); ++it) { if( it != v.begin() ) os << ", "; os << *it;  } return os << "]"; }
 
template < typename T > ostream &operator << ( ostream & os, const multiset< T > &v ) { os << "["; for(auto it = v.begin(); it != v.end(); ++it) { if( it != v.begin() ) os << ", "; os << *it; } return os << "]"; }
 
template < typename F, typename S > ostream &operator << ( ostream & os, const map< F, S > &v ) { os << "["; for(auto it = v.begin(); it != v.end(); ++it) { if( it != v.begin() ) os << ", "; os << it -> first << " = " << it -> second ; } return os << "]";  }
 
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
 
void faltu () { cerr << endl; }
 
template <typename T> void faltu( T a[], int n ) {   for(int i = 0; i < n; ++i) cerr << a[i] << ' '; cerr << endl;  }
 
template <typename T, typename ... hello>  void faltu( T arg, const hello &... rest) {   cerr << arg << ' ';  faltu(rest...);  }

//--------------------------------------------------------------------------------------------------------------------------------------|




                                                    /////    FUNCTIONS     /////



ll bigmod(ll base,ll power){ ll res=1; ll p=base%mod; while(power>0) { if(power%2==1) {  res=((res%mod)*(p%mod))%mod; }  power/=2; p=((p%mod)*(p%mod))%mod; } return res; }

ll inversemod(ll base) { return bigmod(base,mod-2); }

ll poww(ll a,ll b) { ll ans=1; if(!b) return 1; while(b>1) {  if(b&1) { ans=ans*a%mod; } a=a*a%mod; b/=2; }return a*ans%mod; }

int gcd(ll a,ll b) { ll rem; while(b%a!=0)  {  rem=b%a;  b=a;  a=rem; } return a; }


int dx[]={-1, 1 , 0 , 0 , -1 ,-1, 1, 1};
int dy[]={ 0, 0 ,-1 , 1 , -1 , 1,-1, 1};

// up = { -1,0 } , down = { 1,0 } , right = { 0,1 } , left = { 0,-1 }
// up-right = { -1,1 } , up-left = { -1,-1 } , down-right = { 1,1 } , down-left = { 1,-1 }




                                                    ///  CODE STARTS FROM HERE    ///
  

class DSU{
    vector<int> parent,size;  // parent and size
public:
    DSU(int n)
    {
        parent.resize(n+1,0); // resizing parent
        size.resize(n+1,1); // resizing size
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;  // initializing parent of every node itself
        }
    }

    int findUpar(int node)
    {
        if(node==parent[node])
        {
            return node;  // if parent of that node it itself returns
        }

        return parent[node]=findUpar(parent[node]);  // compress the path makes ultimate parent as parent to every connected node was traverse during finding ultimate parent
    }

    void unionBysize(int u,int v)
    {
        int ulpar_u=findUpar(u);  // finding ultimate parent of u and v
        int ulpar_v=findUpar(v);

        if(ulpar_u==ulpar_v)  // if both are in same componet then return
        {
            return;
        }
        if(size[ulpar_u]>=size[ulpar_v])  // if size of ultimate parent of u is greater than or equal to  v then make ultimate parent of v as u
        {
            parent[ulpar_v]=ulpar_u;
            size[ulpar_u]+=size[ulpar_v];  // increase the size of ultimate parent of u by adding size of ultimate parent of v
        }
        else  // else make ultimate parent of u as v
        {
            parent[ulpar_u]=ulpar_v;
            size[ulpar_v]+=size[ulpar_u];
        }
       
    }

    

    

};
void solve()
{
   int n,m;
   cin>>n>>m;
   DSU dsu(n);  // creating object of DSU class

   for(int i=0;i<m;i++)
   {
    int u,v;
    cin>>u>>v;
    dsu.unionBysize(u,v);  // calling unionBysize function to make union of u and v
   }

   int q;
   cin>>q;
   while(q--)
   {
     int x,y;
     cin>>x>>y;
     if(dsu.findUpar(x)==dsu.findUpar(y))  // if ultimate parent of x and y is same then they are in same component
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