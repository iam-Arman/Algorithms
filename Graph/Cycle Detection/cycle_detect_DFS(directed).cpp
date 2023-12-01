#include<bits/stdc++.h>
using namespace std;
inline void file() {
 
#ifndef ONLINE_JUDGE
 
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
 
#endif // ONLINE_JUDGE

}
const int mx=2e5+10;
vector<int> graph[mx];
vector<bool> vis(mx,0);
vector<int> path(mx,0);
int start=-1;
bool dfs(int node)
{
    vis[node]=1;
    path[node]=1;
    for(auto child : graph[node])
    {
        if(vis[child]==0)
        {
            if(dfs(child)==true)
            {
                return true;
            }
        }
        else if(path[child]==1)
        {
            start=child;
            return true;
        }
        
    }
    path[node]=0;
    return false;
}

int main()
{
    file();
    int node,vertice;
    cin>>node>>vertice;
    for(int i=1;i<=node;i++)
    {
        graph[i].clear();
        vis[i]=0;
        path[i]=0;
    }
    map<int,int> mp;
    for(int i=1;i<=vertice;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        mp[x]=y;
    }
    for(int i=1;i<=node;i++)
    {
        if(vis[i]==0)
        {
            if(dfs(i)==true)
            {
                cout<<"Cycle found"<<endl;
                break;
            }
        }
    }
    if(start==-1)
    {
        cout<<"No cycle found"<<endl;
    }
    else
    {
        vector<int> ans;
        ans.push_back(start);
        int x=mp[start];
        while(x!=start)
        {
            ans.push_back(x);
            x=mp[x];
        }
        for(auto x: ans)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
