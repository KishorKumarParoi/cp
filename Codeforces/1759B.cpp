// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 18-11-22
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

int sum(int n) {
	if (n & 1) {
		return ((n + 1) / 2) * n;
	}
	else {
		return (n / 2) * (n + 1);
	}
}

void solve() {
	int n, s; cin >> n >> s;
	vector<int>v(n);
	map<int, int>mp;

	int ss = s;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		s += v[i];
		mp[v[i]]++;
	}

	// cout << sum(6) << " " << sum(7) <<  endl;
	int l = 0, r = 8e9;
	while ((r - l) > 1) {
		int x = l + (r - l) / 2;
		if (sum(x) < s) {
			l = x + 1;
		}
		else {
			r = x;
		}

		// d(l) dl(r)
	}

	// d(sum(l)) d(sum(r)) dl(s)

	int ans = 0;
	if (sum(l) == s) {
		ans = l;
	}
	else if (sum(r) == s) {
		ans = r;
	}
	else {
		cout << "NO" << endl;
		return;
	}

	// d(ss)
	for (int i = 1; i <= ans; ++i) {
		if (mp[i] == 0) {
			// d(i) dl(ss)
			ss -= i;
		}
	}
	// dl(ss)
	if (ss == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	TEST
	solve();

	return 0;
}