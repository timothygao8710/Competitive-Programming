//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

const int mod = 1e9+7;
const int maxn = 2e5 + 7;
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
    for(int i = 1; i<maxn; i++){
        dp[i] = dp[i-1] * i; dp[i] %= mod;
    }

    int T; cin >> T;
    while(T--){
        ll N, K; cin >> N >> K;
        ll each = 0, ret = 0;
        for(int i = 0; i<N; i+=2){
            each += choose(N, i);
            each %= mod;
        }

        //include all same
        ll dpp[2];
        dpp[1] = 0;
        dpp[0] = 1;

        for(int i = 1; i<=K; i++){
            dpp[1] *= binpow(2, N); dpp[1] %= mod;
            dpp[1] += dpp[0]; dpp[1] %= mod;

            if(N%2){
                dpp[0] *= each+1; dpp[0] %= mod;
            }else{
                dpp[0] *= each; dpp[0] %= mod;
            }
        }
        if(N%2){
            cout << dpp[0] << '\n'; continue;
        }
        cout << (dpp[0] + dpp[1])%mod << '\n';
    }
    return 0;
}
