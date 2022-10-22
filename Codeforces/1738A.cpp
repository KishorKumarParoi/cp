// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 13-10-22
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
	vector<int>a(n), b(n);
	int zero = 0, one = 0;
	vector<int>z, o;

	for (int i = 0 ; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0 ; i < n; ++i) {
		cin >> b[i];
		if (a[i]) {
			one++;
			o.push_back(b[i]);
		}
		else {
			zero++;
			z.push_back(b[i]);
		}
	}
	
	sort(all(z));
	sort(all(o));
	reverse(all(z));
	reverse(all(o));
	
	// print(o)
	// print(z)
    
    int i = 0, j = 0, ans = 0;
    while(i < sz(z) || j < sz(o)){
    	if(i == sz(z)){
    		ans += o[j];
    		j++;
    	}
    	else if( j == sz(o)){
    		ans += z[i];
    		i++;
    	}
    	else{
    		ans += z[i]*2;
    		ans += o[i]*2;
    		i++;
    		j++;
    	}
    }
    
    if(sz(z) == sz(o)){
    	ans -= min(z[sz(z) - 1], o[sz(o) - 1]);
    }
    
    cout << ans << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(nullptr));
	TEST
	solve();

	return 0;
}