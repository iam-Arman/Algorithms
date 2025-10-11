                                                  //   Bismillahir Rahmanir Rahim      //
                                                 //     After hardship comes ease     //
                                                //         AUTHOR : iamarman         //

// pragmas
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("unroll-loops")
// #pragma GCC optimization ("strict-overflow")
 
#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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

constexpr ll mod=998244353;
constexpr ll INF=2e18;
constexpr double PI= acos(-1);
constexpr double eps=1e-9;

# define mem(a,b) memset(a,b,sizeof(a))
# define sqr(a) ((a)*(a))
# define lcm(a,b) (a*b)/__gcd(a,b)

# define optimise   { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
# define fraction(a) cout.unsetf(ios::floatfield); cout.precision(a); cout.setf(ios::fixed,ios::floatfield);
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

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

ll gcd(ll a,ll b) { ll rem; while(b%a!=0)  {  rem=b%a;  b=a;  a=rem; } return a; }

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


class node
{
public:
    vector<int> v;
    vector<ll> pref;
    node(){};
    node(int x)
    {
        v.pb(x);
        pref.resize(1,0);
        pref[0]=x;
    }
};

template <typename Node=node>
class SegmentTree
{
public:
    vector<Node> st;

    Node op(Node &a,Node &b)
    {
        node cur;
        int sz=a.v.size()+b.v.size();
        cur.v.resize(sz,0);
        cur.pref.resize(sz,0);
        merge(all(a.v),all(b.v),cur.v.begin());
        cur.pref[0]=cur.v[0];
        for(int i=1;i<sz;i++)
        {
            cur.pref[i]=cur.v[i]+cur.pref[i-1];
        }

        return cur;
    }

    SegmentTree(vector<int> &vec, int n)
    {
        st.resize(4*n,Node());

        function<void(int, int, int)> build = [&](int id, int start, int end)
        {
            if (start == end)
            {
                st[id]=Node(vec[start]);
                return;
            }
            int mid = (start + end) / 2;

            build(2 * id, start, mid);
            build(2 * id + 1, mid + 1, end);

            st[id] = op(st[2*id],st[2*id+1]); 
        };

        build(1, 1, n);
    }

    ll query(int id, int start, int end,ll l,ll r,ll k)
    {
        if (start > r or end < l)
            return 0;
        if (start >= l and end <= r)
        {
            auto lo=upper_bound(all(st[id].v),k);
            int ind=lo-st[id].v.begin();
            if(ind==0) return 0;
            return st[id].pref[ind-1];
        };

        ll mid = start + (end - start) / 2;

        ll left = query(2 * id, start, mid, l, r,k);
        ll right = query(2 * id + 1, mid + 1, end, l, r,k);

        return (left+right); 
    }

};


void solve()
{
    int n;
    cin>>n;
    vector<int> vec(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>vec[i];
    }

    SegmentTree st(vec,n);
    ll prev=0;
    int q;
    cin>>q;
    while(q--)
    {
        ll l,r,k;
        cin>>l>>r>>k;
        l^=prev;
        r^=prev;
        k^=prev;
        ll ans=st.query(1,1,n,l,r,k);
        prev=ans;
        cout<<ans<<el;
    }



    
}

int main()
{ 
    optimise;
    file();
    clock_t start= clock();
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++)
    {
         //cout<<"Case "<<i<<": ";
        solve();
    }
    cerr << "Run Time : " <<((double)(clock() - start) / CLOCKS_PER_SEC)<<el;

}
