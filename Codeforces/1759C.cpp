// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 18-11-22
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
	int l, r, x, a, b;
	cin >> l >> r >> x >> a >> b;

	// d(a) dl(b)
	if (a == b) {
		cout << 0 << endl;
		return;
	}

	if (b - x >= a || b + x <= a) {
		cout << 1 << endl;
		return;
	}

	int ans = 0;
	if (b + x <= r && b - x >= l) {
		ans += 2;
	}
	else if (b + x > r) {
		if (b - x < l) {
			cout << -1 << endl;
			return;
		}
		b -= x;
		ans++;
		if (a != b)
			ans += 2;
	}
	else if (b - x < l) {
		if (b + x > r) {
			cout << -1 << endl;
			return;
		}
		b += x;
		ans++;
		if (b - a >= x) ans++;
		else {
			if (b + x > r && b - x < l) {
				cout << -1 << endl;
				return;
			}
			if(b+x <= r)
				b += x;
			else if(b-x >= l)
				b -= x;
			if()
			ans += 2;
		}
	}

	cout << ans << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	TEST
	solve();

	return 0;
}