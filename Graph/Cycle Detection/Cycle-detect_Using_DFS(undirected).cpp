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

bool cycle_dfs(int node,int parent)
{
    dis.push_back(node);
    vis[node]=1;
    for(auto x: graph[node])
    {
    
        if(vis[x]==0)
        {
            if(cycle_dfs(x,node)==true) // if true then returns true doesnt call for further dfs
            {
                return true;
            }
        }
        else if(vis[x]==1 and x!=parent) 
        {
            return true;
        }
    }
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
    }

    map<pair<int,int>,int>mp;
    for(int i=1;i<=vertice;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x==y) continue;
        int mn=min(x,y);
        int mx=max(x,y);
        if(mp[{mn,mx}]==1) continue;
        graph[mx].push_back(mn);
        graph[mn].push_back(mx);
        mp[{mn,mx}]=1;
        
    }

    bool found=false;

    for(int i=1;i<=node;i++)
    {
        if(vis[i]==0) 
        {  
            found=cycle_dfs(i,-1);
        }
        if(found) break;
    }
    if(found) cout<<"Cycle detected"<<endl;
    else cout<<"No Cycle detected"<<endl;
    

}
