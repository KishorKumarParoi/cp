// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 01-12-22
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

/*
  Focus on Corner Case
    1. N == 1
    2. N == 1, x == 1, y == 1
    3. N == n
*/

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
const int M = 1e9 + 7;
int fact[N];

int BinMultiply(int a, int b, int M) {
	int ans = 0;
	while (b) {
		if (b & 1)
			ans = (ans + a) % M;
		a = (a + a) % M;
		b >>= 1;
	}
	return ans;
}

int BinExpo(int a, int b, int M) {
	a %= M;
	int ans = 1;
	while (b) {
		if (b & 1)
			ans = BinMultiply(ans, a, M) % M;
		a = BinMultiply(a, a, M) % M;
		b >>= 1;
	}
	return ans;
}

void solve() {
	int n, k; cin >> n >> k;
	int ans = (fact[n] * fact[k]) % M;
	int den = (fact[k - n] * fact[n]) % M;
	cout << (ans * BinExpo(den, M - 2, M) % M) % M << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	fact[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = (fact[i - 1] * i) % M;
	}

	TEST
	solve();

	return 0;
}