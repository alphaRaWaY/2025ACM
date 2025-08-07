#include<iostream>
using namespace std;
using ll = long long;
const int MaxN(5e3+5),MOD(998244353);

ll qpow(ll x, ll y) {
	ll res = 1;
	while (y) {
		if (y&1) res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll get(ll a, ll b, ll c, ll d) {
	if (b < d) {
		swap(a, c);
		swap(b, d);
	}
	if (d == 0) return 1;
	ll g = gcd(a, c);
	if (g == 1) return 1;
	return qpow(g, d) * get(g, b - d, c / g, d) % MOD;
}

void solve() {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << get(a, b, c, d) << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
	return 0; 
}