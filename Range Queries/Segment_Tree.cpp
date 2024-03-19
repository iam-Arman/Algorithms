#include<bits/stdc++.h>
using namespace std;
#define ll long long

template <typename T>
class SegmentTree
{
public:
    vector<T> st;

    ll op(ll a,ll b)
    {
        return a+b;
    }

    SegmentTree(vector<T> &vec, int n)
    {
        st.resize(4 * n, 0);

        function<void(int, int, int)> build = [&](int id, int start, int end)
        {
            if (start == end)
            {
                st[id] = vec[start];
                return;
            }
            int mid = (start + end) / 2;

            build(2 * id, start, mid);
            build(2 * id + 1, mid + 1, end);

            st[id] = op(st[2*id],st[2*id+1]); 
        };

        build(1, 1, n);
    }

    ll query(int id, int start, int end, int l, int r)
    {
        if (start > r or end < l)
            return 0;
        if (start >= l and end <= r)
            return st[id];

        int mid = start + (end - start) / 2;

        ll left = query(2 * id, start, mid, l, r);
        ll right = query(2 * id + 1, mid + 1, end, l, r);

        return op(left,right); 
    }

    void update(int id, int start, int end, int ind, int cur)
    {
        if (start > ind or end < ind)
            return;
        if (start == end and start == ind)
        {
            st[id] = cur;
            return;
        }

        int mid = start + (end - start) / 2;

        update(2 * id, start, mid, ind, cur);
        update(2 * id + 1, mid + 1, end, ind, cur);

        st[id] = op(st[2 * id], st[2 * id + 1]); 
    }
};

int main()
{
    int n;
    cin>>n;

    vector<ll> vec(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>vec[i];
    }

    SegmentTree<ll> stree(vec,n);

    int q;
    cin>>q;
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int ind,val;
            cin>>ind>>val;
            vec[ind]=val;
            stree.update(1,1,n,ind,val);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            cout<<stree.query(1,1,n,l,r)<<endl;
        }
    }
}