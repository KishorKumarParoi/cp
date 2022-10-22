// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 08-09-22
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
    int n, m; cin >> n >> m;
    char s[n+10][m+10];
    
    for(int i = 0; i < n+2; ++i){
    	for(int j = 0; j < m+2; j++){
    		s[i][j] = '2';
    	}
    }
    
    //  for(int i = 0; i < n+2; ++i){
    // 	for(int j = 0; j < m+2; j++){
    // 		cout << s[i][j] << " ";
    // 	}
    // 	cout << endl;
    // }
    // cout << endl;
    
    int one = 0;
    for(int i = 1; i <= n; ++i){
    	for(int j = 1; j <= m; ++j){
    	     cin >> s[i][j];
           // if(s[i][j] == '1') one++; 
      }
    }
    
    // for(int i = 0; i < n+2; ++i){
    // 	for(int j = 0; j < m+2; j++){
    // 		cout << s[i][j] << " ";
    // 	}
    // 	cout << endl;
    // }
    // cout << endl;
  
    
    int cnt = 0, z = 0;
    
    for(int i = 1; i <= n; ++i){
    	for(int j = 1; j <= m; ++j){
    		if(s[i][j] =='0'){
    			z++;
    			if(s[i-1][j] == '0') cnt++;
    			else if(s[i+1][j] == '0') cnt++;
    			else if(s[i][j-1] == '0') cnt++;
    			else if(s[i][j+1] == '0') cnt++;
          else if(s[i-1][j-1] == '0') cnt++;
          else if(s[i-1][j+1] == '0') cnt++;
          else if(s[i+1][j-1] == '0') cnt++;
          else if(s[i+1][j+1] == '0') cnt++;
     		}
     		else{
     			one++;
     		}
    	}
    }
    
    if(cnt > 0 && z > 0){
    	cout << one << endl;
    }
    else if(z > 0 && cnt < 1){
    	cout << one - 1LL << endl;
    }
    else{
    	cout << one - 2LL << endl;
    }
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  TEST
  solve();

  return 0;
}