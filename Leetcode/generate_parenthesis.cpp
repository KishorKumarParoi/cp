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
vector<string>valid;

void backtrack(string &s, int open, int close) {

	if (open == 0 && close == 0) {
		valid.push_back(s);
		return ;
	}
	if (open > 0) {
		s.push_back('(');
		backtrack(s, open - 1, close);
		s.pop_back();
	}
	if (close > 0) {
		if (open < close) {
			s.push_back(')');
			backtrack(s, open, close - 1);
			s.pop_back();
		}
	}
}
void solve() {
	int n; cin >> n;
	string s;
	backtrack(s, n, n);
	
	for(auto x : valid){
		cout << x << endl;
	}
	cout << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	TEST
	solve();

	return 0;
}