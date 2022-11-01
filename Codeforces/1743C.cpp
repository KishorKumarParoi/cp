// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 29-10-22
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
	string s; cin >> s;
	vector<int>v(n);

	int one = 0;

	for (int i = 0 ; i < n; ++i) {
		cin >> v[i];
		if (s[i] == '1') {
			one++;
		}
	}

	int ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == '0') {
			if (s[i + 1] == '0') {
				continue;
			}
			else {
				int mini = INT_MAX, sum = 0;
				sum += v[i];
				mini = min(mini, v[i]);
				i++;

				while (s[i] == '1') {
					sum += v[i];
					mini = min(mini, v[i]);
					i++;
				}

				ans += sum - mini;
				i--;
				// d(i)  d(v[i]) dl(ans)
			}
		}
		else{
			ans += v[i];
		}
	}

	if (one == n) {
		ans = accumulate(all(v), 0);
	}

	cout << ans << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	TEST
	solve();

	return 0;
}