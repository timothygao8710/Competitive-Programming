//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

const int maxn = 2e5+9; const ll mod = 1e9+7;
ll dp[maxn];

ll binpow(ll base, ll pow)
{
    if (pow == 0) return 1;
    ll half = binpow(base, pow / 2);
    ll ret = (half * half) % mod;
    if (pow % 2 == 1) ret *= base;
    return ret%mod;
}

ll choose(ll a, ll b){ //big : small
    if(a<0||b<0||a<b) return 0;
    ll ret = dp[a]; ll denom = (dp[a-b]*dp[b])%mod;
    ret *= binpow(denom, mod-2); ret %= mod;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    dp[0] = 1;
    for(int i = 1; i<maxn; i++) dp[i] = (dp[i-1]*i)%mod;
    cout << choose(1000, 690);
    return 0;
}
