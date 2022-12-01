// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 19-11-22
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
	vector<int>v(n + 1), dp(n + 1, 0), mark_end(n + 1, 0);

	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
		dp[i] = dp[i - 1] + v[i];
	}

	bool f = 0;
	if (v[1] == 0) {
		f = 1;
	}

	for (int i = 1; i <= n; ++i) {
		if (i + 1 > n) {
			mark_end[i] = 1;
		}
		else {
			if (v[i + 1] == 0)
				mark_end[i] = 1;
			else
				mark_end[i] = 0;
		}
	}

	int max_freq = 0, ans = 0;
	map<int, int>mp;

	for (int i = 1; i <= n; ++i) {
		mp[dp[i]]++;
		max_freq = max(max_freq, mp[dp[i]]);

		if (mark_end[i] == 1) {
			if (f == 0) {
				ans += mp[0];
				f = 1;
			}
			else {
				ans += max_freq;
			}

			max_freq = 0;
			mp.clear();
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