// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 15-10-22
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
	int n, k; cin >> n >> k;
	string s; cin >> s;
	map<int,int>mp;
	for (auto c : s) {
		mp[c-'a']++;
	}

	// PRINT(mp)
	// cout << endl;
	
	string ans;
	for(int i = 0; i < k; ++i){
		for(int j = 0; j < n/k; ++j){
			if(mp[j] == 0){
				ans += 'a' + j;
				// dl(ans)
				break;
			}
			else{
				mp[j]--;
				if(j == n/k-1)
					ans += 'a' + j + 1;
			}
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