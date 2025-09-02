
template <typename T>
class SegmentTree
{
public:
    vector<T> st;
    vector<T> lazy;
    vector<char> has_lazy;
    int N;

    T op(T a, T b)
    {
        return a + b;
    }

    SegmentTree(vector<T> &vec, int n)
    {
        N = n;
        st.resize(4 * n + 5, 0);
        lazy.resize(4 * n + 5, 0);
        has_lazy.assign(4 * n + 5, 0);

        function<void(int, int, int)> build = [&](int id, int start, int end)
        {
            if (start == end)
            {
                st[id] = vec[start];
                return;
            }
            int mid = (start + end) / 2;
            build(2 * id, start, mid);
            build(2 * id + 1, mid + 1, end);
            st[id] = op(st[2*id], st[2*id+1]);
        };

        build(1, 1, n);
    }

    void apply_set(int id, int start, int end, T val) {
        st[id] = val * (end - start + 1);
        lazy[id] = val;
        has_lazy[id] =1;
    }

    void push(int id, int start, int end) {
        if (!has_lazy[id] || start == end) return;
        int mid = (start + end) / 2;
        apply_set(2*id, start, mid, lazy[id]);
        apply_set(2*id+1, mid+1, end, lazy[id]);
        has_lazy[id] = 0;
    }


    T query(int id, int start, int end, int l, int r)
    {
        if (start > r or end < l)
            return 0;
        if (l <= start && end <= r)
            return st[id];

        push(id, start, end); 

        int mid = start + (end - start) / 2;
        T left = query(2 * id, start, mid, l, r);
        T right = query(2 * id + 1, mid + 1, end, l, r);
        return op(left, right);
    }

    void range_update(int L, int R, T val) { range_update(1,1,N,L,R,val); }
    void range_update(int id, int start, int end, int L, int R, T val)
    {
        if (start > R or end < L) return;
        if (L <= start && end <= R) {
            apply_set(id, start, end, val);
            return;
        }
        push(id, start, end);
        int mid = (start + end) / 2;
        range_update(2*id, start, mid, L, R, val);
        range_update(2*id+1, mid+1, end, L, R, val);
        st[id] = op(st[2*id], st[2*id+1]);
    }


    void update(int id, int start, int end, int ind, int cur)
    {

        range_update(1, 1, N, ind, ind, (T)cur);
    }

    T range_query(int L, int R) { if (L>R) return (T)0; return query(1,1,N,L,R); }
};
