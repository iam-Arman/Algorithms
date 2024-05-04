// constexpr int mod1 = 1000000007;
// constexpr int mod2 = 1000000009;
template<typename T>
class MultiHashing {
private:
    int n;
    string s;
    string rev;
    vector<int> bases = {37,61,79,83,97,53,61,
                         107,127,137,163,191 ,
                         199,211,229,239,263 ,
                         271,281,293 };
                         
    vector<int> mods = {1000000007, 1000000009, 1000000433, 1000001329, 1000001927,
                       1000003051, 1000003253, 1000003397, 1000003579, 1000003751,
                       1000003793, 1000002043, 1000003967, 1000003987, 1000004123,
                       1000004843, 1000006129, 1000006961, 1000012253, 1000015271};

    T base1;
    T base2;
    T mod1;
    T mod2;
    vector<pair<T, T>> prefix_hash;
    vector<pair<T, T>> suffix_hash;
    vector<pair<T, T>> power;
    vector<pair<T, T>> inv;

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
    MultiHashing(const string& str) : s(str) {
        n = s.size();
        base1 = bases[rng() % bases.size()];
        base2 = bases[rng() % bases.size()];
        mod1 = mods[rng() % mods.size()];
        mod2 = mods[rng() % mods.size()];
        prefix_hash.resize(n + 1, {0, 0});
        power.resize(n + 1, {0, 0});
        inv.resize(n + 1, {0, 0});
        precom();
    }

    void precom() {
        power[0] = {1, 1};
        for (int i = 1; i <= n; i++) {
            power[i].first = mul(power[i - 1].first, base1, mod1);
            power[i].second = mul(power[i - 1].second, base2, mod2);
        }

        T inv_base1 = bigmod(base1, mod1 - 2, mod1);
        T inv_base2 = bigmod(base2, mod2 - 2, mod2);
        inv[0] = {1, 1};
        for (int i = 1; i <= n; i++) {
            inv[i].first = mul(inv[i - 1].first, inv_base1, mod1);
            inv[i].second = mul(inv[i - 1].second, inv_base2, mod2);
        }

        for (int i = 1; i <= n; i++) {
            int ch = s[i - 1] - 'a' + 1;
            prefix_hash[i].first = add(prefix_hash[i - 1].first, mul(ch, power[i - 1].first, mod1), mod1);
            prefix_hash[i].second = add(prefix_hash[i - 1].second, mul(ch, power[i - 1].second, mod2), mod2);

        }
    }

    pair<T, T> get_hash(int l, int r) {
        T val1 = sub(prefix_hash[r].first, prefix_hash[l - 1].first, mod1);
        val1 = mul(val1, inv[l].first, mod1);

        T val2 = sub(prefix_hash[r].second, prefix_hash[l - 1].second, mod2);
        val2 = mul(val2, inv[l].second, mod2);

        return {val1, val2};
    }
};
