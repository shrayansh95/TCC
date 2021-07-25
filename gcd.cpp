#include<bits/stdc++.h>
using namespace std;
#define ll long long
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" = " << x << endl;
#else
#define debug(x)
#endif

ll gcd(int a, int b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

void solve() {
	ll n, q, l, r, i;
	cin >> n >> q;


	vector<int> a(n + 1);
	for (i = 1; i <= n; i++)
		cin >> a[i];


	vector<int> prefix(n + 1), suffix(n + 2);
	prefix[1] = a[1];
	suffix[n] = a[n];
	suffix[n + 1] = 0;

	for (i = 2; i <= n; i++)
		prefix[i] = gcd(prefix[i - 1], a[i]);

	for (i = n - 1; i > 0; i--)
		suffix[i] = gcd(suffix[i + 1], a[i]);


	while (q--) {
		cin >> l >> r;
		cout << gcd(prefix[l - 1], suffix[r + 1]) << "\n";
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif
	ll t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}