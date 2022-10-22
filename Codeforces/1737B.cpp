// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 17-10-22
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

double sqroot(int n) {
	double l = 0, r = 2e9;
	while(r - l > 1e-6){
		double mid = (l + r) / 2;
		if(mid * mid > n)
			r = mid;
		else
			l = mid;
	}
	dl(l)
	return l;
}

void solve() {
	int l, r; cin >> l >> r;
	int ans = 0;
	double sqL = sqroot(l), sqR = sqroot(r);
	d(sqL) dl(sqR)
	
	if(sqL == sqR){
		for(int i = 0; i < 3; ++i){
			if(l <= sqL*(sqL+i) &&  sqL*(sqL+i) <= r) ans++;
		}
	}
	else{
		ans = (sqR - sqL - 1) * 3;
		// dl(ans)
		for(int i = 0; i < 3; ++i){
			if(l <= sqL*(sqL+i) && r <= sqL*(sqL+i)) ans++;
			d(sqL*(sqL+i)) d(ans)
			if(l <= sqR*(sqR+i) && r <= sqR*(sqR+i)) ans++; 
			dl(ans)
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