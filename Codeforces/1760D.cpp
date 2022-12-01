// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 21-11-22
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
	vector<int>v(n);
	set<int> st;

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		st.insert(v[i]);
	}

	if (sz(st) == 1) {
		cout << "YES" << endl;
		return;
	}

	int cnt = 0;
	int i = 0;
	// while (v[i] == v[i + 1] && i + 1 < n) {
	// 	i++;
	// }

	// if (i + 1 == n || v[i + 1] > v[i]) {
	// 	cnt++;
	// }

	// d(i) d(v[i]) dl(cnt)

	// int j = n - 1;
	// while (v[j] == v[j - 1] && j > 0) {
	// 	j--;
	// }

	// if (j - 1 == 0 || v[j - 1] > v[j]) {
	// 	cnt++;
	// }

	// d(j) d(v[j]) dl(cnt)

	// i = 0;

	bool f = 0;

	while (i + 1 < n) {
		if (v[i] > v[i + 1]) {
			i++;
			while (v[i] == v[i + 1] && i + 1 < n) {
				i++;
			}
			if (v[i + 1] > v[i] || i + 1 == n ) {
				cnt++;
			}
			f = 1;
		}
		else if (v[i] == v[i + 1]) {
			i++;
		}
		else {
			if (f == 0) {
				cnt++;
				f = 1;
			}
			i++;
		}
	}

	if (f == 0 && v[n - 1] > v[n - 2]) {
		cnt++;
	}

	// dl(cnt)

	if (cnt == 1) {
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