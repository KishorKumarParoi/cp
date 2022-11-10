// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 02-11-22
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

vector<int>v;
int ans = 0;

void Call(int l1, int r1, int l2, int r2) {
	int maxi = 0, mini = INT_MAX;
	for (int i = l1; i <= r1; ++i) {
		maxi  = max(v[i], maxi);
	}

	for (int i = l2; i <= r2; i++) {
		mini = min(v[i], mini);
	}

	// d(maxi) dl(mini)

	if (maxi > mini) {
		int p = l2;
		for (int i = l1; i <= r1; ++i) {
			swap(v[i], v[p++]);
		}
		++ans;
	}

	if (l1 == r1) return;

	int mid1 = (l1 + r1) / 2;
	int mid2 = (l2 + r2) / 2;

	Call(l1, mid1, mid1 + 1, r1);
	Call(l2, mid2, mid2 + 1, r2);
}

void solve() {
	int n; cin >> n;
	v.resize(n + 1);

	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}

	ans = 0;
	int mid = (n + 1) / 2;

	if (is_sorted(v.begin() + 1, v.begin() + n + 1)) {
		cout << 0 << endl;
		return;
	}

	Call(1, mid, mid + 1, n );

	if (is_sorted(v.begin() + 1, v.begin() + n + 1)) {
		cout << ans << endl;
	}
	else {
		cout << -1 << endl;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	TEST
	solve();

	return 0;
}