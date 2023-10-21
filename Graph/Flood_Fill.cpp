#include<bits/stdc++.h>
using namespace std;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

bool isValid(int i,int j,int n)
{
    if(i<1 || i>n || j<1 || j>n)
    {
        return false;
    }
    return true;
}

void dfs(int i,int j,int n,vector<vector<int> > &grid,int color,int newColor,vector<vector<int> > &vis)
{
    vis[i][j]=1;
    grid[i][j]=newColor;

    for(int k=0;k<4;k++)
    {
        int x=i+dx[k];
        int y=j+dy[k];
        if(isValid(x,y,n) && grid[x][y]==color && vis[x][y]==0)
        {
            dfs(x,y,n,grid,color,newColor,vis);
        }
    }
    
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin>>n;

    vector<vector<int> > grid(n+1,vector<int>(n+1));
    vector<vector<int> > vis(n+1,vector<int>(n+1,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>grid[i][j];
        }
    }

    int newColor;
    cin>>newColor;

    int x,y;
    cin>>x>>y;

    int color=grid[x][y];

    dfs(x,y,n,grid,color,newColor,vis);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }







    
   
}