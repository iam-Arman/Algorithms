#include<bits/stdc++.h>
using namespace std;

// probelm link : https://cses.fi/problemset/task/1649

void update(int ind,int val,vector<int> &block,vector<int> &vec,int sz)
{
    int cur_block=(ind+sz-1)/sz;
    vec[ind]=val;
    block[cur_block]=INT_MAX;
    int start=(cur_block-1)*sz+1;
    for(int i=start;i<start+sz;i++)
    {
        block[cur_block]=min(block[cur_block],vec[i]);
    }
}

int query(int l,int r,vector<int> &block,vector<int> &vec,int sz)
{
    int ans=INT_MAX;

    for(int i=l;i<=r;)
    {
        if(i%sz==1 and i+sz<=r)
        {
            ans=min(ans,block[(i+sz-1)/sz]);
            i+=sz;
        }
        else
        {
            ans=min(ans,vec[i]);
            i++;
        }
    }

    return ans;
}


int main()
{
    int n;
    cin>>n;

    int q;
    cin>>q;

    vector<int> vec(n+1);

    int sz=sqrt(n)+1;

    vector<int> block(sz+1,INT_MAX);

    for(int i=1;i<=n;i++)
    {
        cin>>vec[i];
        block[(i+sz-1)/sz]=min(block[(i+sz-1)/sz],vec[i]);
    }

    while(q--)
    {
        int type;
        cin>>type;

        if(type==1)
        {
            int pos,val;
            cin>>pos>>val;
            update(pos,val,block,vec,sz);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            cout<<query(l,r,block,vec,sz)<<endl;
        }
    }


}
