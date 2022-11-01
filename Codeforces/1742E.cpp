// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 30-10-22
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
	vector<int>v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	vector<pair<int, int>>qu, qu_copy;
	for (int i = 0; i < q; ++i) {
		int k; cin >> k;
		qu.push_back({k, i});
	}

	qu_copy = qu;
	sort(all(qu));

	map<int, int>ans;

	int j = 0, tot = 0;
	for (int i = 0; i < q; ++i) {

		if (j == n) {
			ans[qu[i].first] = tot;
			continue;
		}

		while (j < n) {

			if (v[j] <= qu[i].first) {
				tot += v[j];
				j++;
			}
			else {
				ans[qu[i].first] = tot;
				break;
			}
		}
		if (j == n) {
			ans[qu[i].first] = tot;
		}
	}

	for (int i = 0; i < q; ++i) {
		cout << ans[qu_copy[i].first] << " ";
	}
	cout << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	TEST
	solve();

	return 0;
}