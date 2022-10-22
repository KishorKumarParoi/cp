// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 08-09-22
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
            
#define endl "\n"
#define int long long
#define sz(s) (int)s.size()
#define pi acos(-1.0)
#define fr(i,a,b)                         for(int i=a;i<=b;++i)
#define all(v)                            v.begin(),v.end()
#define TEST                              int tc;cin>>tc; while(tc--)
// Debug
#define d(a)                              cout << #a << " : " << a << " ";
#define dl(a)                             cout << #a <<" : " << a << endl;
#define print(v)  for(auto x : v)         {cout<<x<<" ";   }  cout<<endl;
#define PRINT(v)  for(auto x : v)         {cout<<x.first<<" "<<x.second<<endl;}
#define printArr(a,b,arr)                 for(int i=a;i<=b;++i) { cout<<arr[i]<< " ";} cout<<endl;

using namespace std;

const int N   = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    char s[3][3];
    set<char>st;
    
    for(int i = 0; i < 2; ++i){
      for(int j = 0; j < 2; ++j){
          cin >> s[i][j];
          st.insert(s[i][j]);
      }
    }
    
    if(sz(st) == 4)
      cout << 3 << endl;
    else if(sz(st) == 3)
      cout << 2 << endl;
    else if(sz(st) == 2)
      cout << 1 << endl;
    else
      cout << 0 << endl;
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  TEST
  solve();

  return 0;
}