// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 01-12-22
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

/*
  Focus on Corner Case 
    1. N == 1
    2. N == 1, x == 1, y == 1
    3. N == n
*/

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

int phi[N];
void totient() {
	for (int i = 1; i < N; i++) phi[i] = i;
	for (int i = 2; i < N; i++) {
		if (phi[i] == i) {
			for (int j = i; j < N; j += i) phi[j] -= phi[j] / i;
		}
	}
}

int BinMultiply(int a, int b, int M) {
	int ans = 0;
	while (b) {
		if (b & 1)
			ans = (ans + a) % M;
		a = (a + a) % M;
		b >>= 1;
	}
	return ans;
}

int BinExpo(int a, int b, int M) {
	a %= M;
	int ans = 1;
	while (b) {
		if (b & 1)
			ans = BinMultiply(ans, a, M) % M;
		a = BinMultiply(a, a, M) % M;
		b >>= 1;
	}
	return ans;
}

void ssolve() {
	// int a, b, c; cin >> a >> b >> c;
	// cout << BinExpo(a, BinExpo(b, c, M - 1), M) << endl;

	int a, n; cin >> a >> n;
	int val_b = 0, mul = 1;

	vector<int>b(n);
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	totient();

	for (int i = n - 1; i >= 0; i--) {
		int pow = BinExpo(10, n - i - 1, phi[1337]);
		val_b += pow * b[i];
		// d(pow) d(val_b)
		val_b %= phi[1337];
		mul *= 10;
		d(val_b) dl(mul)
	}

	// d(a) dl(val_b)

	cout << BinExpo(a, val_b, 1337) << endl;
}

vector<bool>isPrime(N, 1);
vector<int>divisors[N];
vector<int>lp(N, 0), hp(N, 0);

void sieve() {
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < N; ++i) {
		if (isPrime[i] == true) {
			lp[i] = hp[i] = i;
			for (int j = 2 * i ; j < N; j += i) {
				isPrime[j] = false;
				hp[j] = i;
				if (lp[j] == 0)
					lp[j] = i;
			}
		}
	}

	for (int i = 1; i < N; ++i) {
		for (int j = i; j < N; j += i) {
			divisors[j].push_back(i);
		}
	}
}

pair<int, int> extended_gcd(int a, int b) {
	if (b == 0)
		return {1, 1};
	pair<int, int> p = extended_gcd(b, a % b);
	int x = p.second;
	int y = p.first - (a / b) * p.second;
	return {x, y};
}

void solve() {
	int num, a, b; cin >> num >> a >> b;

	pair<int, int> p = extended_gcd(a, b);
	cout << p.first << " " << p.second << endl;

	vector<int>prime_factors;
	unordered_map<int, int>cnt;
	// d(lp[num]) dl(hp[num])

	print(divisors[num])
	int SOD = accumulate(all(divisors[num]), 0);
	dl(SOD)

	while (num > 1) {
		int prime_factor = hp[num];
		while (num % prime_factor == 0) {
			num /= prime_factor;
			prime_factors.push_back(prime_factor);
			cnt[prime_factor]++;
		}
	}

	PRINT(cnt)
	print(prime_factors)
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  TEST
  solve();

  return 0;
}