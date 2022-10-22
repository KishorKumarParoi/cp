// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 28-08-22
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
vector<int>v;

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    int ad = a * d;
    int bc = b * c;
    
    if(ad == bc){
    	 cout << 0 << endl;
    }
    else if(ad == 0 || bc == 0){
    	cout << 1 << endl;
    }
    else if((ad%bc == 0) || (bc%ad == 0)){
    	cout << 1 << endl;
    }
    else{
    	cout << 2 << endl;
    }
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  TEST
  solve();

  return 0;
}