// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 10-11-22
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

bool CountSubarrayZero(vector<int>&v, int n, int m) {
	unordered_map<int, int>hashTable;
	int curSum = 0, ans = 0;
	hashTable[0] = 1;

	for (int i = 0; i < n; ++i) {
		curSum ^= v[i];
		if (hashTable[curSum ^ m] > 0) {
			ans += hashTable[curSum ^ m];
			// d(i) d(curSum)  dl(hashTable[curSum ^ m])
			if (i % 2 == 0)return true;
		}
		hashTable[curSum]++;
	}

	// dl(ans)
	// PRINT(hashTable)
	return false;
}

void solve() {
	int n, q; cin >> n >> q;
	vector<int>v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	while (q--) {
		int l, r; cin >> l >> r;
		l--, r--;
		vector<int>a(v.begin() + l, v.begin() + r + 1);
		// print(a)
		bool ans = CountSubarrayZero(a, r - l + 1, 0);
		if (ans) {
			cout << 1 << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	// TEST
	solve();

	return 0;
}