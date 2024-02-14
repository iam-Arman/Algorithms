#include<bits/stdc++.h>
using namespace std;

int main()
{
    int node,edge;
    cin>>node>>edge;

    vector<int> graph[node+1];
    for(int i=0;i<edge;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }

    vector<int> indegree(node+1,0);

    for(int i=1;i<=node;i++)
    {
        for(auto it: graph[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    vector<int> order;

    for(int i=1;i<=node;i++)
    {
        if(indegree[i]==0) q.push(i);
    }

    while(!q.empty())
    {
        int node=q.front();
        q.pop();

        order.push_back(node);

        for(auto it: graph[node])
        {
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }

    if(order.size()!=node) cout<<"Cycle is present"<<endl;
    else
    {
        for(auto it: order) cout<<it<<" ";
        cout<<endl;
    }
}