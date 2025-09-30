
using u128 = unsigned __int128;
using u64  = unsigned long long;

// ---------- gcd for u128 ----------
u128 gcd_u128(u128 a, u128 b) {
    while (b != (u128)0) {
        u128 t = a % b;
        a = b;
        b = t;
    }
    return a;
}

// ---------- Modular multiplication & pow (using u128) ----------
u128 mulmod(u128 a, u128 b, u128 mod) {
    return (a * b) % mod;
}

u128 power(u128 a, u128 d, u128 mod) {
    u128 r = (u128)1;
    a %= mod;
    while (d) {
        if (d & 1) r = mulmod(r, a, mod);
        a = mulmod(a, a, mod);
        d >>= 1;
    }
    return r;
}

// ---------- Miller-Rabin ----------
bool isPrime(u128 n) {
    if (n < 2) return false;
    static const u64 smallPrimes[] = {2,3,5,7,11,13,17,19,23,29,31,37};
    for (u64 p : smallPrimes) {
        if (n % p == 0) return n == (u128)p;
    }
    u128 d = n - 1;
    unsigned s = 0;
    while ((d & 1u) == 0u) { d >>= 1; ++s; }
    const u64 bases[] = {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL};
    for (u64 a64 : bases) {
        if ((u128)a64 % n == 0) continue;
        u128 x = power((u128)a64, d, n);
        if (x == 1 || x == n - 1) continue;
        bool composite = true;
        for (unsigned r = 1; r < s; ++r) {
            x = mulmod(x, x, n);
            if (x == n - 1) { composite = false; break; }
        }
        if (composite) return false;
    }
    return true;
}

// ---------- Pollard Rho ----------

inline u128 f_pol(u128 x, u128 c, u128 mod) {
    return (mulmod(x, x, mod) + c) % mod;
}
u128 pollard(u128 n) {
    if (n % 2 == 0) return (u128)2;
    if (n < (u128)4) return n;
    while (true) {
        // pick random seeds (reduce to 64-bit randomness; good enough)
        u64 rx = rng();
        u64 rc = rng();
        u128 x = (u128)( (rx % (u64) ( (u128) (n-2) ) ) ) + 2;
        u128 y = x;
        u128 c = (u128)( (rc % (u64) ( (u128)(n-1) )) ) + 1;
        u128 d = 1;
        while (d == 1) {
            x = f_pol(x, c, n);
            y = f_pol(f_pol(y, c, n), c, n);
            u128 diff = x > y ? x - y : y - x;
            d = gcd_u128(diff, n);
            if (d == n) break;
        }
        if (d != (u128)0 && d != n) return d;
        // otherwise retry
    }
}

// ---------- Factorization ----------
vector<u128> factors;
void factor(u128 n) {
    if (n == (u128)1) return;
    if (isPrime(n)) {
        factors.push_back(n);
        return;
    }
    u128 d = pollard(n);
    if (d == (u128)0 || d == n) { // fallback
        factors.push_back(n);
        return;
    }
    factor(d);
    factor(n / d);
}

// ---------- Count divisors ----------
unsigned long long countDivisors(u128 n) {
    factors.clear();
    factor(n);
    sort(factors.begin(), factors.end());
    unsigned long long ans = 1;
    for (size_t i = 0; i < factors.size();) {
        size_t j = i;
        while (j < factors.size() && factors[j] == factors[i]) ++j;
        unsigned long long exponent = (unsigned long long)(j - i);
        ans *= (exponent + 1ULL);
        i = j;
    }
    return ans;
}
