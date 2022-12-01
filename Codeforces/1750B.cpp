// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 16-11-22
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
	int max_Z = 0, max_O = 0, z = 0, o = 0;
	int cnt_Z = 0, cnt_O = 0;

	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') z++;
		else o++;
	}
	for (int i = 0; i < n; ++i) {
		while (s[i] == '0' && i < n) {
			i++;
			cnt_Z++;
		}
		max_Z = max(max_Z, cnt_Z);
		cnt_Z = 0;
	}

	for (int i = 0; i < n; ++i) {
		while (s[i] == '1' && i < n) {
			i++;
			cnt_O++;
		}
		max_O = max(max_O, cnt_O);
		cnt_O = 0;
	}

	// int a = 3, b = 4, c = 6;
	// cout << max({a, b, c}) << endl;
	cout << max({max_Z * max_Z, max_O * max_O, z * o}) << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	TEST
	solve();

	return 0;
}