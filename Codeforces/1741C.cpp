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
	int n; cin >> n;
	vector<int>v(n + 1);
	int sum[n + 10] = {0};

	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
		sum[i] = sum[i - 1] + v[i];
	}

	int ans = 0, ansIdx = 0, max_len = 0;
	for (int i = 1; i <= n; ++i) {
		int cnt = 1, segSum = 0;
		for (int j = i + 1; j <= n; ++j) {
			segSum += v[j];
			if (segSum == sum[i]) {
				cnt++;
				segSum = 0;
			}
			// d(j) d(segSum) d(sum[i]) d(cnt) dl(ans)
		}

		if (segSum == 0 && ans < cnt) {
			int len = 0, segSum = 0;
			max_len = i;
			
			for (int j = i + 1; j <= n; ++j) {
				segSum += v[i];
				len++;
				if (segSum == sum[i]) {
					max_len = max(len, max_len);
					segSum = len = 0;
				}
			}
			ans = max(ans, cnt);
			ansIdx = i;
		}
	}

	max_len = ansIdx;
	int  segSum = 0, len = 0;
	// d(max_len) d(ansIdx) dl(ans)

	for (int i = ansIdx + 1; i <= n; ++i) {
		segSum += v[i];
		len++;
		if (segSum == sum[ansIdx]) {
			max_len = max(len, max_len);
			segSum = len = 0;
		}
	}

	cout << max_len << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	TEST
	solve();

	return 0;
}