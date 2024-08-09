
vector<ll> primes,primes1;
void seive(ll n)
{
	vector<ll> isprime(n+1,true);
	for(ll i=2;i<=n;i++)
	{
		if(isprime[i])
		{
			for(ll j=i*i;j<=n;j+=i) isprime[j]=false;
		}
	}

	for(int i=2;i<=n;i++)
	{
		if(isprime[i]) primes.pb(i);
	}
}

void segseive(ll low,ll high)
{
	seive(sqrtl(high));
	vector<bool> prime(high-low+100,true);
	int sz=high-low+5;

	for(auto it : primes)
	{

		ll sm=(low/it)*1LL*it;
		if(sm<low) sm+=it;
		
		for(ll i=sm;i<=high;i+=it)
		{
			prime[i-low]=false;
		}
	}
	for(ll i=low;i<=high;i++)
	{
		if(prime[i-low]) primes1.pb(i);
	}
}
