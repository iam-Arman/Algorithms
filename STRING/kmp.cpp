
vector<int> compute_pi(const string &p) {
    int m = p.size();
    vector<int> pi(m);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

vector<int> kmp(const string &t, const string &p) {
    int n = t.size();
    int m = p.size();
    vector<int> matches;
    vector<int> pi = compute_pi(p);
    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && t[i] != p[j])
            j = pi[j - 1];
        if (t[i] == p[j])
            j++;
        if (j == m) {
            matches.push_back(i - m + 1);
            j = pi[m - 1]; 
        }
    }
    return matches;
}
