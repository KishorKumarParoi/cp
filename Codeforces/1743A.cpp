// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 30-10-22
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

int fac(int n){
	int result = 1;
	for(int i = 2; i <= n; ++i){
		result *= i;
	}
	
	return result;
}

int C(int n, int r){
	return fac(n) / fac(r) / fac(n-r);
}

void solve(){
    int n; cin >> n;
    vector<int>v(n);
    
    for(int i = 0; i < n; ++i){
    	cin >> v[i];
    }
    
    int ans = C(10-n, 2) * C(4,2);
    
    cout << ans << endl;
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  TEST
  solve();

  return 0;
}