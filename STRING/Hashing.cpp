
template<typename T>
class Hashing {
private:
    int n;
    string s;
    vector<int> bases = { 37, 44, 53, 67, 72, 77,
                          84, 96, 111, 124, 143,
                          164, 145, 167, 170, 175,
                          184, 199, 203, 222};

    vector<int> mods =  {1000000007, 1000000009, 1000000433, 1000001329, 1000001927,
                         1000003051, 1000003253, 1000003397, 1000003579, 1000003751,
                         1000003793, 1000002043, 1000003967, 1000003987, 1000004123,
                         1000004843, 1000006129, 1000006961, 1000012253, 1000015271};
    T base;
    T mod;
    vector<T> prefix_hash;
    vector<T> power;
    vector<T> inv;

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

public:
    Hashing(const std::string& str) : s(str) {
        n = s.size();
        base = bases[rng() % bases.size()];
        mod = mods[rng() % mods.size()];
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
};
