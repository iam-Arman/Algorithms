

class FFT {
    using cd = complex<double>;
    static constexpr double PI = acos(-1.0);
    void fft(vector<cd>& a, bool invert) const {
        int n = (int)a.size();
        for (int i = 1, j = 0; i < n; ++i) {
            int bit = n >> 1;
            for (; j & bit; bit >>= 1) j ^= bit;
            j ^= bit;
            if (i < j) swap(a[i], a[j]);
        }

        for (int len = 2; len <= n; len <<= 1) {
            double ang = 2 * PI / len * (invert ? -1 : 1);
            cd wlen(cos(ang), sin(ang));
            for (int i = 0; i < n; i += len) {
                cd w(1);
                for (int k = 0; k < len/2; ++k) {
                    cd u = a[i + k];
                    cd v = a[i + k + len/2] * w;
                    a[i + k] = u + v;
                    a[i + k + len/2] = u - v;
                    w *= wlen;
                }
            }
        }
        if (invert) for (cd & x : a) x /= n;
    }

    static int next_pow2(int x) {
        int n = 1;
        while (n < x) n <<= 1;
        return n;
    }

public:

    vector<long long> multiply(const vector<ll>& A, const vector<ll>& B) const {
        if (A.empty() || B.empty()) return {};
        int n = (int)A.size(), m = (int)B.size();
        int need = n + m - 1;
        int sz = next_pow2(need);

        vector<cd> fa(sz);
        for (int i = 0; i < n; ++i) fa[i].real((double)A[i]);
        for (int i = 0; i < m; ++i) fa[i].imag((double)B[i]);

        fft(fa, false);

        vector<cd> fb(sz);
        for (int i = 0; i < sz; ++i) {
            int j = (i == 0 ? 0 : sz - i);
            cd a1 = (fa[i] + conj(fa[j])) * cd(0.5, 0.0);
            cd b1 = (fa[i] - conj(fa[j])) * cd(0.0, -0.5);
            fb[i] = a1 * b1;
        }

        fft(fb, true);

        vector<long long> res(need);
        for (int i = 0; i < need; ++i) res[i] =llround(fb[i].real());
        return res;
    }
};


