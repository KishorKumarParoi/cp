// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 31-10-22
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
	string a, b; cin >> a >> b;
	int i = 0, j = 0;

	if (a == b) {
		cout << "=" << endl;
	}
	else if (a[sz(a) - 1] == b[sz(b) - 1]) {
		if (a[sz(a) - 1] == 'S') {
			if (sz(a) > sz(b)) {
				cout << "<" << endl;
			}
			else {
				cout << ">" << endl;
			}
		}
		else {
			if (sz(a) > sz(b)) {
				cout << ">" << endl;
			}
			else {
				cout << "<" << endl;
			}
		}
	}
	else if (a[sz(a) - 1] == 'S' || b[sz(b) - 1] == 'S') {
		if (a[sz(a) - 1] == 'S' ) {
			cout << "<" << endl;
		}
		else {
			cout << ">" << endl;
		}
	}
	else if (a[sz(a) - 1] == 'L' || b[sz(b) - 1] == 'L') {
		if (a[sz(a) - 1] == 'L' ) {
			cout << ">" << endl;
		}
		else {
			cout << "<" << endl;
		}
	}
	else {
		if (a[sz(a) - 1] == 'L' && b[sz(b) - 1] == 'M') {
			cout << ">" << endl;
		}
		else if (a[sz(a) - 1] == 'M' && b[sz(b) - 1] == 'L') {
			cout << "<" << endl;
		}
		else if (a[sz(a) - 1] == 'S' && b[sz(b) - 1] == 'M') {
			cout << "<" << endl;
		}
		else if (a[sz(a) - 1] == 'M' && b[sz(b) - 1] == 'S') {
			cout << ">" << endl;
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	TEST
	solve();

	return 0;
}