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
	int left = 0, right = 0, f = 0, zero = 0, one = 0;

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		if (f == 0 && v[i] == 0) {
			left = i;
			f = 1;
		}
		if (v[i] == 1) {
			one++;
			right = i;
		}
		if (v[i] == 0) {
			zero++;
		}
	}

	if (zero == n || zero == 0) {
		cout << n - 1 << endl;
		return;
	}

	int ans1 = 0, ans2 = 0;
	vector<int>vv(n);
	vv = v;
	vv[left] = 1;
	int k = zero;
	zero--;

	for (int i = 0; i < n; ++i) {
		if (vv[i] == 1) {
			ans1 += zero;
		}
		else {
			zero--;
		}
	}

	int ans = 0;
	zero = k;
	for (int i = 0; i < n; ++i) {
		if (v[i] == 1) {
			ans += zero;
		}
		else {
			zero--;
		}
	}

	zero = k;
	v[right] = 0;
	zero++;

	for (int i = 0; i < n; ++i) {
		if (v[i] == 1) {
			ans2 += zero;
		}
		else {
			zero--;
		}
	}



	cout << max(ans2, max(ans, ans1)) << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	TEST
	solve();

	return 0;
}