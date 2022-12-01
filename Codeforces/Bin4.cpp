// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 26-11-22
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
	int n, q; cin >> n ;
	vector<int>v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	sort(all(v));
	// print(v)

	cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;

		int  l = 0, r = n, ans = 0;
		while ((r - l) > 1) {
			int m = l + (r - l) / 2;
			if (v[m] <= b)
				l = m + 1;
			else
				r = m;
			// d(l) dl(r)
		}

		// d(v[l]) dl(v[r])
		ans = (v[l] > b ? l : r);
		// d(ans)
		l = 0, r = n;
		while ((r - l) > 1) {
			int m = l + (r - l) / 2;
			if (v[m] < a)
				l = m + 1;
			else
				r = m;
			// d(l) dl(r)
		}

		if (v[l] >= a)
			ans -= l;
		else
			ans -= r;
		// dl(ans)
		cout << ans  << endl;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	// TEST
	solve();

	return 0;
}