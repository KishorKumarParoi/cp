// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 11-11-22
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

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int c[12] {}, max_freq = 0, distinct = 0;

		// string ss = s.substr(i, min(i + 99, n)) ;
		// dl(ss)

		for (int j = i; j < n && j <= i + 99 && c[s[j] - '0'] <= 10; ++j) {
			c[s[j] - '0']++;
			max_freq = max(max_freq, c[s[j] - '0']);
			if (c[s[j] - '0'] == 1) {
				distinct++;
			}
			if (distinct >= max_freq)
				++ans;
		}

	}

	cout << ans << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	TEST
	solve();

	return 0;
}