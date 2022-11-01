// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 26-10-22
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
	int n; cin >> n;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}

	vector<int>ans(n + 1, -1);
	set<int>st;

	for (int i = 1; i <= n; ++i) {
		st.insert(i);
	}

	int maxi = v[1];
	for (int i = 2; i <= n; ++i) {
		if (v[i] > maxi) {
			maxi = v[i];
		}
		else {
			int diff = maxi - v[i];
			auto it = st.lower_bound(diff);
			ans[*it] = i;
			st.erase(it);
		}
	}
	
	for(int i = 1; i <= n; ++i){
		if(ans[i] == -1){
			ans[i] = 1;
		}
	}
	
	for(int i = 1; i <= n; ++i){
		cout << ans[i] << " ";
	}
	cout << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	TEST
	solve();

	return 0;
}