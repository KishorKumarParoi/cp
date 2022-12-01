// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 20-11-22
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
	int n, x; cin >> n ;
	vector<int>v(n);
	vector<bool>b(n, 0);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		// if (v[i] <= x)
		// 	b[i] = 1;
	}

	b[0] = 1;
	for (int i = 1; i < n; ++i) {
		if (v[i] >= v[i - 1]) {
			b[i] = 1;
		}
	}

	print(b)

	int l =  0, r = n - 1 , ans = 0;
	while ((r - l) > 1) {
		int mid = l + (r - l) / 2;
		if (b[mid])
			l  = mid + 1;
		else {
			ans = mid;
			r = mid - 1;
		}
		d(l) dl(r)
	}

	d(l) dl(r)
	d(v[l]) dl(v[r])
	cout << r << " " << v[r] << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	TEST
	solve();

	return 0;
}