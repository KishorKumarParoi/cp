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

vector<int>pairs[1010];

void solve() {
	int n; cin >> n;
	vector<int>v(n + 1);
	vector<int>idx[1010];

	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
		idx[v[i]].push_back(i);
	}
	
	int ans = -1;
	for(int i = 1; i <= 1000; ++i){
		for(int j : pairs[i]){
			if(!idx[i].empty() && !idx[j].empty()){
				ans = max(ans, idx[i].back() + idx[j].back());
			}
		}
	}
	
	cout << ans << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	for (int i = 1; i <= 1000; ++i) {
		for (int j = 1; j <= 1000; ++j) {
			if (__gcd(i, j) == 1) {
				pairs[i].push_back(j);
			}
		}
	}
	
	TEST
	solve();

	return 0;
}