

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xBF58476D1CE4E5B9ULL;
        x = (x ^ (x >> 27)) * 0x94D049BB133111EBULL;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const noexcept {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return (size_t)splitmix64(x + FIXED_RANDOM);
    }
};
struct xorshift64star {
    size_t operator()(uint64_t x) const noexcept {
        static const uint64_t FIXED = chrono::steady_clock::now().time_since_epoch().count();
        x ^= FIXED;
        x ^= x >> 12;
        x ^= x << 25;
        x ^= x >> 27;
        x *= 0x2545F4914F6CDD1DULL;
        return (size_t)x;
    }
};
struct fast_hash {
    size_t operator()(uint64_t x) const noexcept {
        static const uint64_t FIXED = chrono::steady_clock::now().time_since_epoch().count();
        x += FIXED;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = x ^ (x >> 27);
        return (size_t)x;
    }
};
