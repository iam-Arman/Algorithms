class TrieNode
{
public:
    TrieNode *left;
    TrieNode *right;
    int cnt=0;
    TrieNode()
    {
        left=NULL;
        right=NULL;
        cnt=0;
    }
};

class Trie
{
    TrieNode *root;
public:

    Trie()
    {
        root=new TrieNode();
    }

    void insert(int n)
    {
        TrieNode *curr=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(1&(n>>i));
            if(bit==0)
            {
                if(curr->left==NULL)
                {
                    curr->left=new TrieNode();
                }
                curr=curr->left;
                curr->cnt++;
            }
            else
            {
                if(curr->right==NULL)
                {
                    curr->right=new TrieNode();
                }
                curr=curr->right;
                curr->cnt++;
            }
        }
    }

    void remove(int n) 
    {
        TrieNode* curr = root;

        for (int i = 31; i >= 0; i--) 
        {
            if(curr==NULL)
            {
                break;
            }
            
            int bit = (n >> i) & 1;

            if (bit == 0) 
            {
                curr = curr->left;
                curr->cnt--;
            } 
            else 
            {
                curr = curr->right;
                curr->cnt--;
            
            }
        }

    } 

    int max_xor_pair(int n)
    {
        TrieNode *curr=root;
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            if(curr==NULL)
            {
                break;
            }
            int bit=(1&(n>>i));

            if(bit==0)
            {
                if(curr->right!=NULL and curr->right->cnt>0)
                {
                    ans+=(1<<i);
                    curr=curr->right;
                }
                else 
                {
                    curr=curr->left;
                }
            }
            else
            {
                if(curr->left!=NULL and curr->left->cnt>0)
                {
                    ans+=(1<<i);
                    curr=curr->left;
                }
                else
                {
                    curr=curr->right;
                }
            }
        }
        return ans;
    }

    int find_x_such_that_x_xor_y_less_than_or_equal_k(int y,int k)
    {
        TrieNode *curr=root;
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            if(curr==NULL)
            {
                break;
            }
            int bity=(1&(y>>i));
            int bitk=(1&(k>>i));
            if(bity)
            {
                if(bitk)
                {
                    if(curr->right!=NULL)
                    {
                        ans+=curr->right->cnt;
                    }
                    curr=curr->left;
                }
                else
                {
                    curr=curr->right;
                }
            }
            else
            {
                if(bitk)
                {
                    if(curr->left!=NULL)
                    {
                        ans+=curr->left->cnt;
                    }
                    curr=curr->right;
                }
                else curr=curr->left;
            }
        }
        if(curr!=NULL) ans+=curr->cnt;

        return ans;
    }

    int subarray_less_than_k(int n,int k)
    {
        TrieNode *curr=root;
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            if(curr==NULL)
            {
                break;
            }
            int bitk=(1&(k>>i));
            int bitn=(1&(n>>i));

            if(bitn==bitk)
            {
                if(bitk)
                {
                    if(curr->right!=NULL)
                    {
                        ans+=curr->right->cnt;
                    }
                }
                curr=curr->left;
            }
            else
            {
                if(bitk)
                {
                    if(curr->left!=NULL)
                    {
                        ans+=curr->left->cnt;
                    }
                }
                curr=curr->right;
            }

        }

        return ans;
    }

};
