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
	string s; cin >> s;
	bool f = true;

	for (int i = 0; i < sz(s) - 1; ++i) {
		if (s[i] == 'Y' && s[i + 1] != 'e') {
			f = false;
			break;
		}
		else if (s[i] == 'e' && s[i + 1] != 's') {
			f = false;
			break;
		}
		else if (s[i] == 's' && s[i + 1] != 'Y') {
			f = false;
			break;
		}
		else if (s[i] != 'Y' && s[i] != 'e' && s[i] != 's') {
			f = false;
			break;
		}
	}

	int i = sz(s) - 1;

	if (s[i] != 'Y' && s[i] != 'e' && s[i] != 's') {
		f = false;
	}

	if (f) {
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