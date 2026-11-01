/*
================================================================================
A. Fraction and Six
Time Limit: 1 second | Memory Limit: 256 megabytes
================================================================================

You are given two strings p
 and q
, consisting of lowercase English letters.

Interpret the string p
 as the product of variables written in the numerator of a fraction, and the string q
 as the product of variables written in the denominator. Each character represents a variable.

Since multiplication is commutative, the variables in both the numerator and the denominator may be reordered arbitrarily. In addition, any variable that appears in both the numerator and the denominator may be cancelled. Note that a single occurrence of a variable in the denominator can only cancel exactly one occurrence of that variable in the numerator and vice versa.

Determine whether it is possible to simplify the fraction so that the resulting expression is exactly equal to the string six
. In other words, after performing any number of cancellations and rearrangements, the remaining variables in the numerator must form the string six
, and no variables may remain in the denominator.

For example, if p=sinx
 and q=n
, then the variable n
 can be cancelled, leaving six
 in the numerator.

Input
The first line of the input contains a single integer t
 (1<=t<=100
) - the number of test cases. The description of each test case follows.

The first line of each test case contains two integers n
 and m
 (1<=n,m<=100
) - the lengths of the strings p
 and q
, respectively.

The second line of each test case contains a string p
 denoting the numerator of the fraction. It is guaranteed that the length of the string p
 is equal to n
 and that it contains only lowercase English letters.

The third line of each test case contains a string q
 denoting the denominator of the fraction. It is guaranteed that the length of the string q
 is equal to m
 and that it contains only lowercase English letters.

Output
For each test case, print "YES" if you can simplify the fraction so that the resulting expression is exactly equal to the string six
 and "NO" otherwise.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes" and "Yes" will be recognized as a positive response).

Example:
Input:

5
4 1
sinx
n
6 7
xixsms
mixsxim
8 5
fixtures
frute
3 3
abc
def
5 10
sixty
codeforces
Output:

YES
NO
YES
NO
NO
Note
In the first test case, the variable n appears in both the numerator and the denominator, so it can be cancelled. The remaining variables in the numerator are s, i, and x, which can be reordered to obtain six.

In the second test case, after cancelling all possible common variables, the numerator contains only s while the denominator contains only mi. Therefore, the fraction cannot be simplified to six.

In the third test case, the variables f, r, u, t, and e can be cancelled from both sides. The remaining variables in the numerator are s, i, and x, which can be reordered to form six.
================================================================================
*/

// Radhe Radhe Shyam Shyam Vrindaban

// 01-11-26
#include <bits/stdc++.h>
            
#define endl "\n"
#define int long long
#define sz(s) (int)s.size()
#define pi acos(-1.0)
#define all(v)                            v.begin(),v.end()
#define TEST                              int tc;cin>>tc; while(tc--)
// Debug
#define d(a)                              cout << #a << " : " << a << " ";
#define dl(a)                             cout << #a <<" : " << a << endl;
#define print(v)  for(auto x : v)         {cout<<x<<" ";   }  cout<<endl;
#define PRINT(v)  for(auto x : v)         {cout<<x.first<<" "<<x.second<<endl;}
#define printArr(a,b,arr)                 for(int i=a;i<=b;++i) { cout<<arr[i]<< " ";} cout<<endl;

using namespace std;

// const int N   = 1e6 + 5;
// const int MOD = 1e9 + 7;

void solve(){
  int n, m;
  cin >> n >> m;
  string p, q;
  cin >> p >> q;

  if (n - m != 3) {
    cout << "NO" << endl;
    return;
  }

  vector<int> cnt_p(26, 0), cnt_q(26, 0);
  for (char c : p) cnt_p[c - 'a']++;
  for (char c : q) cnt_q[c - 'a']++;

  for (int i = 0; i < 26; i++) {
    int diff = cnt_p[i] - cnt_q[i];
    char ch = (char)('a' + i);
    if (ch == 's' || ch == 'i' || ch == 'x') {
      if (diff != 1) {
        cout << "NO" << endl;
        return;
      }
    } else {
      if (diff != 0) {
        cout << "NO" << endl;
        return;
      }
    }
  }

  cout << "YES" << endl;
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  TEST
  solve();

  return 0;
}
