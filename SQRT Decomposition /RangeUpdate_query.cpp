#include<bits/stdc++.h>
using namespace std;
#define ll long long

// probelm link : https://cses.fi/problemset/task/1651

void update(int l,int r,ll val,vector<ll> &block,vector<ll> &vec,int sz)
{
    for(int i=l;i<=r;)
    {
        if(i%sz==1 and i+sz<=r)
        {
            block[(i+sz-1)/sz]+=val;  // update block
            i+=sz;
        }
        else
        {
            vec[i]+=val;
            i++;
        }
    }
}

ll query(int pos,vector<ll> &block,vector<ll> &vec,int sz)
{
    int cur_block=(pos+sz-1)/sz;

    ll ans=1LL*block[cur_block]+vec[pos];

    return ans;
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int n;
    cin>>n;

    int q;
    cin>>q;

    vector<ll> vec(n+1);

    int sz=sqrt(n)+1;

    vector<ll> block(sz+1,0);

    for(int i=1;i<=n;i++)
    {
        cin>>vec[i];
    }

    while(q--)
    {
        int type;
        cin>>type;

        if(type==1)
        {
            int l,r;
            ll val;
            cin>>l>>r>>val;
            update(l,r,val,block,vec,sz);
        }
        else
        {
            int pos;
            cin>>pos;

            cout<<1LL*query(pos,block,vec,sz)<<"\n";
        }
    }


}
