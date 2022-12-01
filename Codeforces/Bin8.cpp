// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 27-11-22
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

/*
  Focus on Corner Case
    1. N == 1
    2. N == 1, x == 1, y == 1
    3. N == n
*/

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
	int b, n; cin >> b >> n;
	int time[n + 10], ballon[n + 10], rest[n + 10];

	for (int i = 0; i < n; ++i) {
		cin >> time[i] >> ballon[i] >> rest[i];
	}

	int l = 1, r = 1e18;
	vector<int>v(n);

	while ((r - l) > 1) {
		int m = l + (r - l) / 2;

		int tot = 0;
		for (int i = 0; i < n; ++i) {
			int x = time[i] * ballon[i] +  rest[i];
			int xx = (m / x) * ballon[i]  + min(ballon[i], (m % x) / (time[i]));
			tot += xx;
			if (xx >= b)
				v[i] = b, b = 0;
			else {
				v[i] = xx;
				b -= xx;
			}
		}

		if (tot < b)
			l = m + 1;
		else
			r = m;
	}

	// d(l) dl(r)

	int tot = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		int x = time[i] * ballon[i] +  rest[i];
		tot += (l / x) * ballon[i]  + min((l % x) / (time[i]), ballon[i]);
	}

	if (tot >= b)
		ans = l;
	else
		ans = r;

	cout << ans << endl;
	for (int i = 0; i < n; ++i) {
		int x = time[i] * ballon[i] +  rest[i];
		int xx = (ans / x) * ballon[i]  + (ans % x) / (time[i]);


	}
	print(v)
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	// TEST
	solve();

	return 0;
}