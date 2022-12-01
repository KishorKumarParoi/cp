// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 27-11-22
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
	int n, x, y;
	cin >> n >> x >> y;

	int l = 1, r = 1e18;
	--n;

	if (n == 0) {
		cout << min(x, y) << endl;
		return;
	}

	while (l <= r) {
		int m = l + (r - l) / 2;
		int cnt = 0;
		cnt += (m / x) + (m / y);
		if (cnt < n)
			l = m + 1;
		else {
			r = m;
		}

		// d(l) d(r) d(m) dl(cnt)
		if (l == r)
			break;
	}

	if (l >= n)
		cout << l + min(x, y) << endl;
	else
		cout << r + min(x, y) << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	// TEST
	solve();

	return 0;
}