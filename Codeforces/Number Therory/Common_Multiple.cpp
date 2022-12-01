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

const int N   = 2e5 + 5;
const int MOD = 1e9 + 7;
// unordered_map<int, int>mp;
// unordered_map<int, int>multiple_cnt;

int mp[N];
int multiple_cnt[N];

void solve() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		mp[x]++;
	}

	for (int i = 1; i < N; ++i) {
		for (int j = i; j < N; j += i) {
			multiple_cnt[i] += mp[j];
		}
	}

	int k; cin >> k;
	while (k--) {
		int l, r; cin >> l >> r;
		int ans = multiple_cnt[l] + multiple_cnt[r];
		int lcm = (l * r) / __gcd(l, r);
		if (lcm < N)
			ans -= multiple_cnt[lcm];
		cout <<  ans << endl;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	// TEST
	solve();

	return 0;
}