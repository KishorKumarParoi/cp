// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 23-10-22
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
	int n; char c;
	cin >> n >> c;
	string s; cin >> s;

	s = s + s;
	
	int last = -1;
	for(int i = 2*n - 1; i >= n; i--){
		if(s[i] == 'g'){
			last = i;
		}
	}
	
	int ans = 0;
	for(int i = n-1; i >= 0; i--){
		if(s[i] == 'g') last = i;
		if(s[i] == c){
			ans = max(ans, last - i);
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