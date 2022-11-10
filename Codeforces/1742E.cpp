// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 05-11-22
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
	int n, q; cin >> n >> q;
	vector<int>v(n + 1), height(n + 1, 0), max_height(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
		height[i] = height[i - 1] + v[i];
		max_height[i] = max(max_height[i - 1], v[i]);
	}

	// print(v)
	// print(height)
	// print(max_height)

	while (q--) {
		int x; cin >> x;
		// int id = upper_bound(all(max_height), x) - max_height.begin();
		// d(x) d(id) dl(height[id])
		// // cout<< height[id-1] << " ";

		int l = 1, r = n, ans = 0;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (max_height[mid] <= x) {
				ans = height[mid];
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}

		cout << ans << " ";
	}
	cout << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	TEST
	solve();

	return 0;
}