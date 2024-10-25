constexpr ll mod=1000012253;
template<typename T>
class Hashing {
private:
    int n;
    string s;
    T base;
    vector<T> prefix_hash;
    vector<T> power;
    vector<T> inv;

    vector<int> bases = {37,61,79,83,97,53,61,
                         107,127,137,163,191 ,
                         199,211,229,239,263 ,
                         271,281,293};

    T rng() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<T> dis(0, std::numeric_limits<T>::max());
        return dis(gen);
    }

    T mul(T a, T b, T mod) {
        return ((1LL * a % mod) * (b % mod)) % mod;
    }

    T add(T a, T b, T mod) {
        return (1LL * a + b) % mod;
    }

    T sub(T a, T b, T mod) {
        return ((a % mod) - (b % mod) + 2LL * mod) % mod;
    }

    T bigmod(T base, T power, T mod) {
        T res = 1;
        while (power > 0) {
            if (power & 1) {
                res = mul(res, base, mod);
            }
            base = mul(base, base, mod);
            power >>= 1;
        }
        return res;
    }

public:
    Hashing(const std::string& str) : s(str) {
        n = s.size();
        base = bases[rng() % bases.size()];
        prefix_hash.resize(n + 1, 0);
        power.resize(n + 1, 0);
        inv.resize(n + 1, 0);
        precom();
    }

    void precom() {
        power[0] = 1;
        for (int i = 1; i <= n; i++) {
            power[i] = (1LL * power[i - 1] * base) % mod;
        }

        T inv_base = bigmod(base, mod - 2, mod);
        inv[0] = 1;
        for (int i = 1; i <= n; i++) {
            inv[i] = mul(inv[i - 1], inv_base, mod);
        }

        prefix_hash[0] = 0;
        for (int i = 1; i <= n; i++) {
            int ch = s[i - 1] - 'a' + 1;
            prefix_hash[i] = (1LL * prefix_hash[i - 1] + mul(ch, power[i - 1], mod)) % mod;
        }
    }

    T get_hash(int l, int r) {
        T val = sub(prefix_hash[r], prefix_hash[l - 1], mod);
        val = mul(val, inv[l], mod);
        return val;
    }

    T get_new_hash(string &s)
    {
        T val=0;
        for(int i=0;i<s.size();i++)
        {
            int ch=s[i]-'a'+1;
            val=add(val,mul(ch,power[i],mod),mod);
        }
        val=mul(val,inv[1],mod);
        return val;
    }

    void get_new_hash_string(string &s)
    {
        int n=s.size();
        prefix_hash[0] = 0;
        for (int i = 1; i <= n; i++) {
            int ch = s[i - 1] - 'a' + 1;
            prefix_hash[i] = (1LL * prefix_hash[i - 1] + mul(ch, power[i - 1], mod)) % mod;
        }
    }

    T combine(T hash1, T hash2, int len1) {
        return add(mul(hash1, power[len1], mod), hash2, mod);
    }
};
