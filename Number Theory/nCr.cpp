
const int MAXN = 2e6 + 5;

vector<long long> fact(MAXN), inv_fact(MAXN);

 void precompute() {
    fact[0] = 1;
    for(int i = 1; i < MAXN; ++i) {
        fact[i] = fact[i-1] * i % MOD;
    }
    mint cur=fact[MAXN-1];      
    cur=cur.inv();    
    inv_fact[MAXN-1]=cur.v;
    for(int i = MAXN - 2; i >= 0; --i) {
        inv_fact[i] = inv_fact[i+1] * (i+1) % MOD;
    }
 }

long long nCr(int n, int r) {
    if(r < 0 || r > n) return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

long long nPr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv_fact[n - r] % MOD;
}

