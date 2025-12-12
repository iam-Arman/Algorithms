struct Cool_Bitset {
    vector<uint64_t> bits;
    int64_t b, n;

    Cool_Bitset(int64_t _b = 0) {
        init(_b);
    }

    void init(int64_t _b) {
        b = _b;
        n = (b + 63) / 64;
        bits.assign(n, 0);
    }

    void clear() {
        b = n = 0;
        bits.clear();
    }

    void reset() {
        bits.assign(n, 0);
    }

    void _clean() {
        if (b != 64 * n)
            bits.back() &= (1LLU << (b - 64 * (n - 1))) - 1;
    }

    bool get(int64_t index) const {
        return bits[index / 64] >> (index % 64) & 1;
    }

    void set(int64_t index, bool value) {
        assert(0 <= index && index < b);
        bits[index / 64] &= ~(1LLU << (index % 64));
        bits[index / 64] |= uint64_t(value) << (index % 64);
    }

    // --- NEW: Right Shift Assign (>>=) ---
    void operator>>=(int64_t shift) {
        if (shift >= b) {
            reset();
            return;
        }
        if (shift == 0) return;

        int64_t div = shift / 64;
        int64_t mod = shift % 64;

        for (int64_t i = 0; i < n; i++) {
            uint64_t val = 0;
            // Get the main part from the block 'div' away
            if (i + div < n) {
                val = bits[i + div] >> mod;
            }
            // If there's a remainder, we need to grab the "overflow" from the next block
            if (mod != 0 && i + div + 1 < n) {
                val |= bits[i + div + 1] << (64 - mod);
            }
            bits[i] = val;
        }
        _clean();
    }

    // --- NEW: Left Shift Assign (<<=) ---
    void operator<<=(int64_t shift) {
        if (shift >= b) {
            reset();
            return;
        }
        if (shift == 0) return;

        int64_t div = shift / 64;
        int64_t mod = shift % 64;

        // Iterate backwards to avoid overwriting data we need later
        for (int64_t i = n - 1; i >= 0; i--) {
            uint64_t val = 0;
            // Get the main part from 'div' blocks behind
            if (i - div >= 0) {
                val = bits[i - div] << mod;
            }
            // If there's a remainder, grab the top bits from the previous block
            if (mod != 0 && i - div - 1 >= 0) {
                val |= bits[i - div - 1] >> (64 - mod);
            }
            bits[i] = val;
        }
        _clean();
    }

    // --- NEW: Shift Operators (creates new bitset) ---
    Cool_Bitset operator>>(int64_t shift) const {
        Cool_Bitset res(*this);
        res >>= shift;
        return res;
    }

    Cool_Bitset operator<<(int64_t shift) const {
        Cool_Bitset res(*this);
        res <<= shift;
        return res;
    }

    // --- Bitwise AND ---
    Cool_Bitset& operator&=(const Cool_Bitset& other) {
        assert(b == other.b);
        for (int i = 0; i < n; i++) bits[i] &= other.bits[i];
        return *this;
    }

    Cool_Bitset operator&(const Cool_Bitset& other) const {
        Cool_Bitset res(b);
        for (int i = 0; i < n; i++) res.bits[i] = bits[i] & other.bits[i];
        return res;
    }

    // --- NEW: Bitwise OR ---
    Cool_Bitset& operator|=(const Cool_Bitset& other) {
        assert(b == other.b);
        for (int i = 0; i < n; i++) bits[i] |= other.bits[i];
        return *this;
    }

    Cool_Bitset operator|(const Cool_Bitset& other) const {
        Cool_Bitset res(b);
        for (int i = 0; i < n; i++) res.bits[i] = bits[i] | other.bits[i];
        return res;
    }

    // --- NEW: Bitwise XOR ---
    Cool_Bitset& operator^=(const Cool_Bitset& other) {
        assert(b == other.b);
        for (int i = 0; i < n; i++) bits[i] ^= other.bits[i];
        return *this;
    }

    Cool_Bitset operator^(const Cool_Bitset& other) const {
        Cool_Bitset res(b);
        for (int i = 0; i < n; i++) res.bits[i] = bits[i] ^ other.bits[i];
        return res;
    }

    // --- NEW: Bitwise NOT (Flip) ---
    Cool_Bitset operator~() const {
        Cool_Bitset res(b);
        for (int i = 0; i < n; i++) res.bits[i] = ~bits[i];
        res._clean();
        return res;
    }

    int64_t count() const {
        int64_t res = 0;
        for (int i = 0; i < n; i++)
            res += __builtin_popcountll(bits[i]);
        return res;
    }

    int64_t find_first() const {
        for (int i = 0; i < n; i++)
            if (bits[i] != 0)
                return 64 * i + __builtin_ctzll(bits[i]);
        return -1;
    }

    int64_t find_next(int x) const {
        for (int i = x + 1; i < x + 64; i++) {
            if (get(i)) return i;
        }
        for (int i = x / 64 + 1; i < n; i++)
            if (bits[i] != 0)
                return 64 * i + __builtin_ctzll(bits[i]);
        return -1;
    }
};
