
struct SuffixArray {
    string s;
    int n;
    vector<int> sa;
    vector<int> lcp;

    SuffixArray(string _s):s(_s),n(_s.length()){
        s+=char(0); 
        n++; 
        constructSA();
        constructLCP();
    }

    void constructSA() {
        const int ALPHABET = 256; 
        int m = max(n, ALPHABET);
        sa.resize(n+5);
        vector<int> rank(n+5), new_rank(n+5);
        vector<int> cnt(m+5,0);
        
        for (int i = 0; i < n; i++){
            rank[i] = (unsigned char)s[i];
            cnt[rank[i]]++;
        }
        for (int i = 1; i < m; i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) sa[--cnt[rank[i]]] = i;

        vector<int> p(n+5);
        for (int k = 1; k < n; k <<= 1) {
            int cur = 0;
            
            for (int i = n - k; i < n; i++) p[cur++] = i;
            for (int i = 0; i < n; i++) {
                if (sa[i] >= k) p[cur++] = sa[i] - k;
            }
            fill(cnt.begin(), cnt.begin() + m, 0);
            for (int i = 0; i < n; i++) cnt[rank[p[i]]]++;
            for (int i = 1; i < m; i++) cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; i--) sa[--cnt[rank[p[i]]]] = p[i];

            new_rank[sa[0]] = 0;
            int classes = 1;
            for (int i = 1; i < n; i++) {
                bool first_half_same = rank[sa[i]] == rank[sa[i - 1]];
                bool second_half_same = true;
                
                if (sa[i] + k < n && sa[i - 1] + k < n) {
                    second_half_same = (rank[sa[i] + k] == rank[sa[i - 1] + k]);
                } else {
                    second_half_same = (sa[i] + k >= n && sa[i - 1] + k >= n);
                }

                if (!first_half_same || !second_half_same) classes++;
                new_rank[sa[i]] = classes - 1;
            }
            
            rank = new_rank;
            m = classes;
            if (m == n) break;
        }
    }

    void constructLCP() {
        lcp.assign(n+5, 0);
        vector<int> rank(n+5);
        for (int i = 0; i < n; i++) rank[sa[i]]=i;
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (rank[i] == 0) {
                k = 0;
                continue;
            }
            int j = sa[rank[i] - 1];
            while (i + k < n && j + k < n && (unsigned char)s[i + k] == (unsigned char)s[j + k]) k++;
            lcp[rank[i]] = k;
            if (k > 0) k--;
        }
    }

};
