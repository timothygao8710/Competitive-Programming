//Author: timg8710

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

#define pb push_back

#define f first
#define s second

const int mod = 1e9+7;

int binpow(ll base, ll pow)
{
    if (pow == 0) return 1;
    ll half = binpow(base, pow / 2);
    ll ret = (half * half) % mod;
    if (pow % 2 == 1) ret *= base;
    return ret%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll x = binpow(2, mod - 2);
	cout << x << "\n";  // 500000004
	cout << (2 * x % mod == 1);
    return 0;
}
