/*
One Day You will become RED Coder Kishore;
Just Keep breathing & Practicing in your own way;

Please Chant The Holy Name Of Lord Krishna(The Supreme Personality Of Godhead)

      "Hare Krishna Hare Krishna Krishna Krishna Hare Hare
       Hare Rama Hare Rama Rama Rama Hare Hare ......."

Surrender yourself unto the Lotus Feet of Krishna, serve devotees and Srila Prabhupada
*/
//03-03-22
#include <bits/stdc++.h>

#define endl "\n"
#define ff first
#define ss second
#define MP make_pair
#define int long long
#define vi vector<int>
#define pi pair<int,int>
#define pb emplace_back
#define err 1e-8
#define sz(s) (int)s.size()
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) !!(x & (1LL << k))
#define all(v)                            v.begin(),v.end()
#define fr(i,a,b)                         for(int i=a;i<b;i++)
#define d(a)                              cout << #a << " : " << a << " ";
#define dl(a)                             cout<< #a <<" : " << a << endl;
#define print(v)  for(auto x : v)         {cout<<x<<" ";   }  cout<<endl;
#define PRINT(v)  for(auto x : v)         {cout<<x.first<<" "<<x.second<<endl;}
#define TEST                              int tc;cin>>tc; while(tc--)
#define printArr(a,b,arr)                 for(int i=a;i<b;++i) { cout<<arr[i]<< " ";} cout<<endl;
#define yes                               cout<< "Yes"<<endl
#define no                                cout<< "No"<<endl
using namespace std;

void kkp()
{
//#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
//#endif
}

void time()
{
#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
#endif
}

const int N   = 1e6 + 5;
const int MOD = 1e9 + 7;
//int ar[N],br[N];

int josephus(int n,int k)
{

    if(n==1)
        return 1;
    else
    {
        return (josephus(n-1,k)+k-1)%n +1;
        cout<<n<< " ";
    }
}

void solve()
{
    // Can you solve it by brute force?
    // kkp
    // Are you sure you want to code so soon?? -_-
    // Simplify your code a little more. :)

    int n,k;
    cin>>n>>k;
    cout<<josephus(n,k)<<endl;
}

int32_t main()
{
    //kkp();
    ios_base::sync_with_stdio(!cin.tie(0));

    //TEST
    solve();

    return 0;
}


