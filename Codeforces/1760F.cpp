// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 22-11-22
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
int n, c, d;

bool isPossible(int mid) {
	int sum = 0;
	for (int i = 0; i < d; ++i) {
		int id = i % (mid + 1);
		sum += v[id];
	}

	if (sum >= c)
		return true;
	return false;
}
void solve() {
	cin >> n >> c >> d;
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	sort(v.rbegin(), v.rend());

	int l = 0, r = d + 1 , res = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (isPossible(mid)) {
			res = midl
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	d(l) dl(r)

	if (l == d + 1) {
		cout << "Infinity" << endl;
	}
	else if (l == -1) {
		cout << "Impossible" << endl;
	}
	else {
		cout << l << endl;
	}

}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	TEST
	solve();

	return 0;
}