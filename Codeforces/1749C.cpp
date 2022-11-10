// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 04-11-22
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

bool isPossible(int k) {
	multiset<int>st;

	for (int i = 0; i < sz(v); ++i) {
		st.insert(v[i]);
	}

	st.insert(1000);

	for (int i = 1; i <= k; ++i) {
		auto it = st.upper_bound(k - i + 1);
		if (it == st.begin()) {
			return false;
		}
		--it;
		if (*it == 1000) {
			return false;
		}
		st.erase(it);

		if (!st.empty()) {
			int x = *st.begin();
			st.erase(st.begin());
			st.insert(x + k - i + 1);
		}
	}

	return true;
}

void solve() {
	int n; cin >> n;
	v.clear();
	v.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	int l = 0, r = 1e9;
	while ((r - l) > 1) {
		int mid = (l + r) / 2;
		if (isPossible(mid)) {
			l = mid;
		}
		else {
			r = mid - 1;
		}
	}

	if (isPossible(r)) {
		cout << r << endl;
	}
	else if (isPossible(l)) {
		cout << l << endl;
	}
	else {
		cout << 0 << endl;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	TEST
	solve();

	return 0;
}