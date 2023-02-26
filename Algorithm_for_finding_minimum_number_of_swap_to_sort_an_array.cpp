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

/// THIS algorithm is used to find the minimum number of swap to sort an array ///
/// first we have to make a pair of the array and its index ///
/// then we have to sort the pair according to the array ///
/// then we have to count the number of swap to make make the pair index equal to the initaial index ///
/// for example if we have a pair of (2,3 is index)  and our current index is 0 then we have to swap this pair with the pair of index 3  then the pair at index 3 will come to index 0 the we will have to check if the index of the pair is 0 or not if not we will have to do the same step again suppose now we have a pair (2,2) that means we have to swap this pair will the pair at index 2 then again have to cheek if the 0 indexed pair is now at position or not if not do the same steps again and again
/// time complexity is O(n*logn)

void solve()
{
   int n;
   cin>>n;
   vector<int> vec(n);
   for(int i=0;i<n;i++)
   {
    cin>>vec[i];
   }
   vector< pair<int,int> > v;
   for(int i=0;i<n;i++)
   {
    v.push_back(make_pair(vec[i],i));
   }
    sort(v.begin(),v.end());
    int cnt=0;

    for(int i=0;i<n;i++)
    {
      pair<int,int> p=v[i];
      int ind=v[i].second;
      while(i!=ind)
      {
        cnt++;
        swap(v[i],v[ind]);
        ind=v[i].second;
      }
    }
    cout<<cnt<<endl;


}

int main()
{
    optimise;
    //file();
    test{

    solve();

    }

    

}

//problem link : https://practice.geeksforgeeks.org/problems/minimum-swaps/1
