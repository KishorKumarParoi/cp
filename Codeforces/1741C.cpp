// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 02-11-22
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

void solve(){
    int n; cin >> n;
    vector<int>v(n+1);
    int sum[n+10] = {0};
    
    for(int i = 1; i <= n; ++i){
    	cin >> v[i];
    	sum[i] += sum[i-1] + v[i];
    }
    
    int ans = n;
    for(int i  = 1; i <= n; ++i){
    	int cnt = 0, cur = 0, tot = 0, thick = 0;
    	bool ok = true;
    	
    	for(int j = 1; j <= n; ++j){
    		cur += v[j];
    		cnt++;
    		if(cur > sum[i]){
    			ok = false;
    			break;
    		}
    		if(cur == sum[i]){
    			thick = max(cnt, thick);
    			cur = 0;
    			cnt = 0;
    		}
    	}
    	// d(sum[i]) d(thick) dl(ok)
    	
    	if(ok && cur == 0){
    		ans = min(ans, thick);
    	}
    }
    cout << ans << endl;
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  TEST
  solve();

  return 0;
}