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

int binpow(ll base, ll pow)
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
    for(ll i = 1; i<maxn; i++){
        dp[(int)i] = (dp[i-1]*i)%mod;
    }   

    int T, N, l, r; cin >> T;
    while(T--){
        cin >> N >> l >> r;
        ll unconstraint = min(1-l, r-N), rem = N, pos = N/2;
        ll ret = choose(N, pos); ret %= mod;
        if(N%2) ret *=2; ret %= mod;
        ret %= mod; 
        ret *= unconstraint; ret %= mod;
        for(int i = 1;; i++){
            if(i+unconstraint > 1-l){
                rem--; ret %= mod;
            }
            if(i+unconstraint > r-N){
                rem--; pos--; ret %= mod;
            }
            if(rem < 0) break; 
            ret += choose(rem, pos); ret %= mod;
            if(N%2) ret += choose(rem, pos+1);
            ret %= mod;
            // cout << i << " " << ret << endl;
        }
        cout << ret << '\n';
    }
    return 0;
}
