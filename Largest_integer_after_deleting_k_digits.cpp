                                          //   Bismillahir Rahmanir Rahim      //
                                         //      SHAHRIAR MAHMUD ARMAN        //
                                        //         AUTHOR : iamarman         //


#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>

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
ll mod=1000000000+7;

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


                                                    /////    FUNCTIONS     /////



ll bigmod(ll base,ll power)
{
  ll res=1;
  ll p=base%mod;
  while(power>0)
  {
    if(power%2==1)
    {
      res=((res%mod)*(p%mod))%mod;
      //res*=p;
    }
    power/=2;
    p=(p%mod)*(p%mod);
  }
  return res;
}


long long LOG(long long base, long long n)
{  
  long long cnt=0;
while(n>0)
{
 n=n/base;
 cnt++;
}
return (cnt-1);
}


ll poww(ll a,ll b)
{
  ll ans=1;
  if(!b) return 1;
  while(b>1)
  {
    if(b&1)
    {
      ans=ans*a%mod;
    }
    a=a*a%mod;
    b/=2;
  }
  return a*ans%mod;
}

int gcd(ll a,ll b)
{
  ll rem;
  while(b%a!=0)
  {
    rem=b%a;
    b=a;
    a=rem;
  }
  return a;
}


int GCD(ll a,ll b)
{
  if(a==b) return a;
  else if(b==0) return a;
  else return GCD(b,a%b);
}

bool sort_by_sec(const pair<int,int> &a,const pair<int,int> &b)
{
    if(a.first>b.first) return true;
    else if(a.first==b.first)
    {
        return a.second<b.second;
    }
    else return false;
}



                                                    ///  CODE STARTS FROM HERE    ///


                                                    

/// This is a problem to find the largest integer after deleting k digits from a given integer ///  
/// This is a problem of stack ///
/// This is a problem of greedy algorithm ///
/// To solve this problem first we have to take a empty stack and we have to check if the stack is empty or the top element of the stack is greater than or equal the current element if it is then we will push it to stack becuase we have to make the largest integer ///
/// If the top element of the stack is smaller than the current element then we will pop the top element of the stack and we will decrease the value of k untill the top element of stack is greater or the stack is empty ///
/// then we will check if k is greater than 0 or not if it is greater than 0 then we will pop the top element of the stack and we will decrease the value of k ///
/// then we will take a string and we will push the elements of the stack to the string ///
/// then we will check if the last element of the string is 0 or not if it is 0 then we will pop the last element of the string because after we reverse the string the zeros will come in the front but we dont want any zeros in the front ///
/// then we will reverse the string and we will print the string ///
/// if string is empty then we will print 0 ///



void solve()
{
  
  string s;
  cin>>s;
  int k;
  cin>>k;

  stack<char> st;

  for(int i=0;i<s.size();i++)
  {
      while(!st.empty() and k>0 and s[i]>st.top())
      {
        st.pop();
        k--;
      }
      st.push(s[i]);
  }
  while(k>0 and !st.empty())
  {
     st.pop();
     k--;
  }

  string ans="";

  while(!st.empty())
  {
     ans+=st.top();
     st.pop();
  }

  while(ans[ans.size()-1]=='0' and !ans.empty())
  {
      ans.pop_back();
  }
  if(ans.size()==0)
  {
    cout<<0<<endl;
    return;
  }

  reverse(all(ans));
  cout<<ans<<endl;
 
}
    

int main()
{
    optimise;
    file();
  //test{

    solve();

   // }

    

}



// problem link : https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/largest-number-7-eee0b7c3/
