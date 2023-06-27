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

bool cycle_bfs(int node)
{
    queue<pair<int,int> > q;
    q.push({node,-1}); // storing node with their parent parent node has no parent so parent -1

    vis[node]=1; // making the node visited
    
    while(!q.empty())
    {
        node=q.front().first; 
        int parent=q.front().second;
        q.pop();
        for(auto x: graph[node])
        {
            if(vis[x]==0) 
            {
                vis[x]=1;
                q.push({x,node});
            }
            else if(vis[x]==1 and x!=parent) return true; 

        }
    }
    return false; // return false if no cycle found
}

int main()
{
    file();
    int node,vertice;
    cin>>node>>vertice;

    map<pair<int,int>,int > mp;
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
    {   found=false;
        if(vis[i]==0) 
        {
            found=cycle_bfs(i);
        }
        if(found) break;
    }
    if(found) cout<<"Cycle detected"<<endl;
    else cout<<"No Cycle detected"<<endl;

}