auto digsum=[&](auto self,ll n)->ll
    {
        if(n<10) return n*(n+1)/2;

        ll p=1,d=0;
        while(p*10<=n)
        {
            p*=10;
            d++;
        }

        ll msd=n/p;
        ll rem=n%p;
        ll total=msd*45LL*d*(p/10);
        total+=msd*(msd-1)/2*p;

        total+=(rem+1)*msd;

        total+=self(self,rem);
        return total;
    };
