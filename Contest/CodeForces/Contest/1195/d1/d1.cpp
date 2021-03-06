// /*
//  * Author: apikdech
//  * Time: 22:42:36 17-07-2019
// **/

// #include <bits/stdc++.h>
// using namespace std;
// typedef unsigned long long ll;
// const ll MOD = 998244353;
// ll ans = 0;

// ll f(ll x) {
// 	ll i = 10, res = 0;
// 	while(x) {
// 		ll tmp = x % 10;
// 		tmp = (tmp * i);
// 		res = (res + tmp);
// 		x /= 10;
// 		i = i*100;
// 		// cout << tmp << " " << i << "\n";
// 		// cout << i << "\n";
// 	}
// 	return res;
// }

// int main() {
// 	ios::sync_with_stdio(0); cin.tie(0);
// 	ll n;
// 	cin >> n;
// 	for (int i = 0; i < n; i++) {
// 		ll x;
// 		cin >> x;
// 		ll tmp = f(x);
// 		ans = (ans + tmp + tmp/10LL) % MOD;
// 	}
// 	ans = (ans * n) % MOD;
// 	cout << ans << "\n";
// 	return 0;
// }

/*
 * Author: apikdech
 * Time: 23:18:10 17-07-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int MOD = 998244353, N = 1e5 + 5;
ll a[N], cnt[20], ans = 0;

ll f(ll x, int len) {
	ll res = 0, i = 10;
	len--;
	while(x) {
		res += (x % 10) * i;
		res %= MOD;
		x /= 10;
		if (len > 0) i *= 100;
		else i *= 10;
		len--;
	}
	return res % MOD;
}

ll rf(ll x, int len) {
	ll res = 0, i = 1;
	while(x) {
		res += (x % 10) * i;
		res %= MOD;
		x /= 10;
		if (len > 0) i *= 100;
		else i *= 10;
		len--;
	}
	return res % MOD;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int tmp = a[i], x = 0;
		while(tmp) x++, tmp/=10;
		cnt[x]++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 10; j++) {
			if (cnt[j] == 0) continue;
			// cout << f(a[i], j) << " " << rf(a[i], j) << " " << j <<"\n";
			ans = (ans + cnt[j]*f(a[i], j) + cnt[j]*rf(a[i], j)) % MOD;
		}
	}
	cout << ans % MOD << "\n";
	return 0;
}
