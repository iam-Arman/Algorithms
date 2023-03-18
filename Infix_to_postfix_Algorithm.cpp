                                          //   Bismillahir Rahmanir Rahim      //
                                         //      SHAHRIAR MAHMUD ARMAN        //
                                        //         AUTHOR : iamarman         //


#include<bits/stdc++.h>

                                             ////       MACROS       ////

//---------------------------------------------------------------------------------------------------------------------------------|

# define ll long long                                                                                                              
# define test int test; cin>>test; while(test--)
# define rep(i,a,b) for(int i=a;i<b;i++)
# define rep_n(i,a,b) for(int i=a;i<=b;i++)
# define rep_rev(i,a,b) for(int i=b;a>=1;i--)
# define pb push_back
# define el "\n"
# define optimise   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); cin.clear(); 
# define R0 return 0
# define all(v) v.begin(),v.end()
# define srt(vvv) sort(vvv.begin(),vvv.end())
# define sp " "
# define vii vector<int>
# define vll vector<long long>
# define yess cout<<"YES"<<el
# define noo cout<<"NO"<<el
# define PI 2*acos(0.0)
ll mod=10000000+7;

//----------------------------------------------------------------------------------------------------------------------------------|


//                                             ///      NAMESPACE     ///

using namespace std;


                     /// THIS IS FOR GIVING INPUT AND GETTING OUTPUT IN A FILE INSTEAD OF TERMINAL OR CONSOLE   ///


inline void file() {

#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}





                                                    ///  CODE STARTS FROM HERE    ///


/// This algorithm is used to convert infix expression to postfix expression ///
/// first we have to create a function to find the precedence of the operator ///
/// then we have to create a stack and a string ///
/// then we have to traverse the string ///
/// if the character is an operand then we have to add it to the string ///
/// if the character is an opening bracket then we have to push it to the stack ///
/// if the character is a closing bracket then we have to pop the stack until we get the opening bracket ///
/// if the character is an operator then we have to pop the stack until we get the operator with lower precedence ///
/// then we have to push the operator to the stack ///
/// then we have to pop the stack and add it to the string ///
/// then we have to return the string ///
/// then we have to call the function and print the result ///
/// Time complexity is O(n) ///

int prec(char c)
{
    if(c=='^')
        return 3;
    else if(c=='*' or c=='/')
        return 2;
    else if(c=='+' or c=='-')
        return 1;
    else return -1;
}

string infix_to_postfix(string s)
{
    string ans="";
    stack<char> st;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='a' and s[i]<='z')
        {
            ans+=s[i];
        }
        else if(s[i]=='(')
            st.push(s[i]);
        else if(s[i]==')')
        {
            while(!st.empty() and st.top()!='(')
            {
                ans+=st.top();
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while(!st.empty() and prec(st.top())>prec(s[i]))
            {
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    return ans;
}

int main()
{
    optimise;
    //file();
    cout<<"Enter the infix expression :";
    string s;
    cin>>s;
    cout<<"The postfix expression is :"<<infix_to_postfix(s)<<el;

    

}
