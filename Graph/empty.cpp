

ll extended_euclid(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        y=0, x=1;  
        return a;
    }
    ll x1,y1;
    ll g = extended_euclid(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return g;
}
ll inverse(ll a,ll m)
{
    ll x,y, g=extended_euclid(a,m,x,y);
    if(g!=1)
        return -1;

    return ((x%m)+m)%m;
}
