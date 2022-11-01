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

	vector<pair<int, int>>ans;
	int sum = 0, i = 1, f = 0;

	for (; i < n; ++i) {
		
		if (v[i] == v[i + 1] && !f) {
			ans.push_back(make_pair(i, i + 1));
			++i;
		}
		else {
			if (f) {
				f = 0;
			}
			else {
				f = 1;
			}
			ans.push_back({i, i});
			sum += v[i];
		}
	}
	
	// d(sum)
	
	if(i == n){
		ans.push_back({n,n});
		sum += v[n];
	}
	
	// dl(sum)
	
	if (sum == 0) {
		// cout << "Hello Jonogon ";
		cout << sz(ans) << endl;
		for (auto x : ans) {
			cout << x.first << " " << x.second << endl;
		}
	}
	else {
		// cout << "Hello KKP ";
		cout << -1 << endl;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	TEST
	solve();

	return 0;
}