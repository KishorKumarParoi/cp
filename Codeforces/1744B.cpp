// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 19-10-22
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#define endl "\n"
#define int unsigned long long
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
	vector<int>v(n);
	int cnt1 = 0, cnt2 = 0, sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		if (v[i] & 1) {
			cnt1++;
		}
		else {
			cnt2++;
		}
		sum += v[i];
	}

	while (q--) {
		int type, val; cin >> type >> val;

		if (type & 1) {
			cnt1 *= val;
		}
		else {
			cnt2 *= val;
		}
		cout << sum + cnt1 + cnt2 << endl;
	}

}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	TEST
	solve();

	return 0;
}