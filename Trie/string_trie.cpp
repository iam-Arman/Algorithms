class Trie
{
public:
    static const int N=26;

    struct Node
    {
        int next[N];
        int pref;
        int end;
        Node()
        {
            fill(next,next+N,-1);
            pref=0;
            end=0;
        }
    };

    vector<Node> tree;
    Trie(int sz=1)
    {
        tree.reserve(sz);
        tree.emplace_back();
    }

    void insert(string &s)
    {
        int cur=0;
        tree[cur].pref++;
        for(auto it : s)
        {
            int ch=it-'a';
            if(tree[cur].next[ch]==-1)
            {
                tree[cur].next[ch]=(int)tree.size();
                tree.emplace_back();
            }
            cur=tree[cur].next[ch];
            tree[cur].pref++;
        }
        tree[cur].end++;
    }

    int count(string &s)
    {
        int cur=0;
        for(auto it : s)
        {
            int ch=it-'a';
            if(tree[cur].next[ch]==-1) return 0;
            cur=tree[cur].next[ch];
        }
        return tree[cur].end;
    }

    int prefixnode(string &s)
    {
        int cur=0;
        for(auto it : s)
        {
            int ch=it-'a';
            if(tree[cur].next[ch]==-1) return -1;
            cur=tree[cur].next[ch];
        }
        return cur;
    }

    void erase(string &s)
    {
        if(count(s)==0) return;
        int cur=0;
        tree[cur].pref--;
        for(auto it : s)
        {
            int ch=it-'a';
            cur=tree[cur].next[ch];
            tree[cur].pref--;
        }
        tree[cur].end--;
    }

    vector<string> top_k_macting(string &s,int k)
    {
        vector<string>vec;
        string cur=s;
        int node=prefixnode(s);

        if(node==-1) return vec;

        auto rec=[&](auto&& self,int node)->void
        {
            if(vec.size()>=k) return;

            if(tree[node].end)
            {
                for(int i=0;i<tree[node].end;i++) vec.pb(cur);
            }
            for(int to=0;to<N;to++)
            {
                if(tree[node].next[to]!=-1 and vec.size()<k)
                {
                    cur+=char('a'+to);
                    self(self,tree[node].next[to]);
                    cur.pop_back();
                }
            }
        };
      
        rec(rec,node);
          while(vec.size()>k) vec.pop_back();
        return vec;
    };

    vector<string> atmost_k_mismatch(string &s,int k)
    {
        vector<string> vec;
        int sz=s.size();

        string cur="";
        auto rec=[&](auto&& self,int node,int cnt,int len)->void
        {
            if(cnt>k) return;

            if(tree[node].end and len==sz) vec.pb(cur);
            for(int to=0;to<N;to++)
            {
                if(tree[node].next[to]!=-1 and cnt<=k and len<sz)
                {
                    cur+=char('a'+to);
                    self(self,tree[node].next[to],cnt+((s[len]-'a')!=to),len+1);
                    cur.pop_back();
                }
            }
        };

        rec(rec,0,0,0);
        return vec;
    }

};
