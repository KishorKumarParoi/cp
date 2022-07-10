// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 10-07-22
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
            
#define endl "\n"
#define int long long
#define sz(s) (int)s.size()
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

const int N   = 1e5 + 5;
const int MOD = 1e9 + 7;
int n, k, kase = 1, x;

int f(int n){
    return (n*(n+1))/2;
}

void solve(){
    cin >> k >> x;
    int l = 1, r = 100, lim = 100;
    while(l < r){
         d(l) d(r)
        int m = l + (r - l)/2;
        if(f(m) <= x)
            l = m ;
        else
            r = m - 1;
        d(m) d(f(m)) dl(x)
    }
    
    d(l) dl(r)
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  TEST
  solve();

  return 0;
}