/*
 * Author: apikdech
 * Time: 18:31:24 14-10-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

ll lx, rx;

ll gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }
    x0 *= (c / g);
    y0 *= (c / g);
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void shift_solution(ll & x, ll & y, ll a, ll b, ll cnt) {
    x += cnt * b;
    y -= cnt * a;
}

ll find_all_solutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {
    ll x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    ll sign_a = a > 0 ? +1 : -1;
    ll sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    ll lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    ll rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    ll lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    ll rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    lx = max(lx1, lx2);
    rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll n, p, w, d, x, y, z, g, x0, y0, z0;
	cin >> n >> p >> w >> d;
	ll ans = find_all_solutions(w, d, p, 0, 1e12, 0, 1e12);
	if (!ans) cout << "-1\n";
	else {
		ll l = lx, r = rx, m;
		cout << lx << " " << rx << "\n";
		x0 = rx;
		y0 = (p - w*x0)/d;
		z0 = n - (x0 + y0);
		cout << x0 << " " << y0 << " " << z0 << "\n";
		if (z0 < 0) cout << "-1\n";
		else cout << x0 << " " << y0 << " " << z0 << "\n";
	}
	return 0;
}

//999999999999
//999999999999