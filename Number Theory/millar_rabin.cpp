using u64 = unsigned long long;
using u128 = __uint128_t;

u64 modmul(u64 a, u64 b, u64 m){ return (u128)a*b % m; }
u64 modpow(u64 a, u64 e, u64 m){
    u64 r = 1;
    while (e){
        if (e & 1) r = modmul(r, a, m);
        a = modmul(a, a, m);
        e >>= 1;
    }
    return r;
}
bool isPrime64(u64 n){
    if (n < 2) return false;
    for (u64 p : {2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL,29ULL,31ULL,37ULL})
        if (n % p == 0) return n == p;
    u64 d = n-1; int s = 0;
    while ((d & 1) == 0){ d >>= 1; ++s; }
    for (u64 a : {2ULL,325ULL,9375ULL,28178ULL,450775ULL,9780504ULL,1795265022ULL}){
        if (a % n == 0) continue;
        u64 x = modpow(a, d, n);
        if (x == 1 || x == n-1) continue;
        bool comp = true;
        for (int r = 1; r < s; ++r){
            x = modmul(x, x, n);
            if (x == n-1){ comp = false; break; }
        }
        if (comp) return false;
    }
    return true;
}
