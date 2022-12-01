// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 26-11-22
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
	int w, h, n; cin >> w >> h >> n;
	int l = 1, r = 1;

	while ((r / w) * (r / h) < n)
		r <<= 1;
	
	while ((r - l) > 1) {
		int m = l + (r - l) / 2;
		if ((m / w) * (m / h) < n ) {
			l = m + 1;
		}
		else {
			r = m;
		}
	}

	// d(l) dl(r)

	if ((l / w) * (l / h) >= n)
		cout << l  << endl;
	else
		cout << r  << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	// TEST
	solve();

	return 0;
}