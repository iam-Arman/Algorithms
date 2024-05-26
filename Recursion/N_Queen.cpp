void solve()
{   
    int n;
    cin>>n;

    vector<vector<int> > vis(n+1,vector<int> (n+1,0));

    int ans=0;

    function<void(int)> rec=[&](int row)
    {
        
        if(row==n+1)
        {
            ans++;
            return;
        }

        for(int col=1;col<=n;col++)
        {
            int x=col;
            int y=col;
            bool ok=true;
            for(int roww=row-1;roww>=1;roww--)
            {
                x-=1;
                y+=1;
                if(vis[roww][col] or(x>=1 and  vis[roww][x]) or (y<=n and vis[roww][y]))
                {
                    ok=false;
                    break;
                }
            }
            if(ok)
            {
                vis[row][col]=1;
                rec(row+1);
                vis[row][col]=0;
            }
        }
    };

    rec(1);
    cout<<ans<<el;

}
