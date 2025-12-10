vector<int> manacher(string s) {
    string t = "^#";
    for (char c : s) {
        t += c;
        t += "#";
    }
    t += "$";
    int n = t.size();
    vector<int> p(n,0);
    int l = 1, r = 1; 

    for (int i = 1; i < n - 1; i++) {
        int i_mirror = l + (r - i);
        if (r > i) {
            p[i] = min(r - i, p[i_mirror]);
        }
        while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) {
            p[i]++;
        }
        if (i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
        }
    }
    return p;
}
