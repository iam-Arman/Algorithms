#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node
{
public:
    ll val; // may change
    Node()
    {
        val = 0; // may change
    }

    Node(ll v)  // actual node
    {            
        val = v; // may change
    }

    void merge(Node &l, Node &r)
    {
        val = l.val + r.val; // may change
    }
};

class Update
{
public:
    ll val; // may change
    Update(ll x)   // actual update
    {           
        val = x; // may change
    }

    void apply(Node &a)   // apply update to given node
    {               
        a.val = val; // may change
    }
};

template <typename Node, typename Update>
class SegmentTree
{
public:
    vector<Node> tree;
    vector<ll> arr; // type may change
    int n, s;

    SegmentTree(int _n, vector<ll> &v) // change if any update
    {
        n = _n;
        arr = v;
        s = 1;
        while (s < 2 * n)
            s *= 2;

        tree.resize(s);

        fill(tree.begin(),tree.end(), Node());

        build(1, 1, n);
    }

    void build(int id, int start, int end)  // never change
    { 

        if (start == end)
        {
            tree[id] = Node(arr[start]); // may change according to node structure
            return;
        }

        int mid = start + (end - start) / 2;

        build(2 * id, start, mid);
        build(2 * id + 1, mid + 1, end);

        tree[id].merge(tree[2 * id], tree[2 * id + 1]);
        tree[id].merge(tree[2 * id], tree[2 * id + 1]);
    }

    void update(int id, int start, int end, int index, Update &val)  // never change
    { 

        if (start > index or end < index)
            return;

        if (start == end)
        {
            val.apply(tree[id]);
            return;
        }

        int mid = start + (end - start) / 2;

        update(2 * id, start, mid, index, val);
        update(2 * id + 1, mid + 1, end, index, val);

        tree[id].merge(tree[2 * id], tree[2 * id + 1]);
    }

    Node query(int id, int start, int end, int l, int r)  // never change
    { 

        if (start > r or end < l)
            return Node();

        if (start >= l and end <= r)
            return tree[id];

        int mid = start + (end - start) / 2;

        Node left = query(2 * id, start, mid, l, r);
        Node right = query(2 * id + 1, mid + 1, end, l, r);
        Node ans;
        ans.merge(left, right);
        return ans;
    }

    void make_update(int ind, int val) // pass as many parameter required
    {
        Update new_update = Update(val); // may change according to update structure
        update(1, 1, n, ind, new_update);
    }

    Node make_query(int left, int right)
    {
        return query(1, 1, n, left, right);
    }
};

void solve()
{
    int n,q;
    cin>>n>>q;

    vector<ll> vec(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>vec[i];
    }

    SegmentTree<Node,Update> stree(n,vec);
    

    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int ind,val;
            cin>>ind>>val;
            vec[ind]=val;
            stree.make_update(ind,val);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            cout<<stree.make_query(l,r).val<<"\n";
        }
    }



}


int main()
{ 
    solve();
}