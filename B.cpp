// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 23-08-22
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
    int n, m, k; cin >> n >> m >> k;
    string a, b, c;
    cin >> a >> b;
    
    sort(all(a));
    sort(all(b));
    
    int i = 0, j = 0, p = 0, q = 0;
    
    while(i < n && j < m){
        if((a[i] < b[j] && p < k) || (q == k)){
            q = 0;
            p++;
            c += a[i];
            i++;
        }
        else {
            p = 0;
            q++;
            c += b[j];
            j++;
        }
    }
    
    cout << c << endl;
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  TEST
  solve();

  return 0;
}