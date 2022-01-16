//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

const int maxn = 2e5+9; 
const ll mod = 998244353;

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
    for(int i = 1; i<maxn; i++) dp[i] = (dp[i-1]*i)%mod;
    int N, K; cin >> N >> K;
    string t; cin >> t;
    if(K == 0) {
        cout << 1 << '\n'; return 0;
    }
    vector<ll> nums(N), pref(N); ll ret = 1;
    for(int i = 0; i<N; i++) nums[i] = t[i] - '0';
    pref[0] = nums[0];
    for(int i = 1; i<N; i++) pref[i] = pref[i-1] + nums[i];
    int lastEnd = -1, lastBeg = -1;
    for(int i = 0; i<N; i++){
        if(nums[i] == 0) continue; //change?
        int has = 0; int j = i;
        for(; j<N; j++){
            has += nums[j]; if(has > K) break;
        }
        j--;
        // cout << has << endl;
        if(has < K) break;
        
        ll tot = j - lastBeg; //total range
        ll subr = lastEnd - lastBeg; //last range
        ll sub = (lastEnd < 0 ? 0 : pref[lastEnd] - pref[lastBeg]);
        // cout << i << " " << tot << " " <<  subr << " " << sub << endl;
        ret += choose(tot, K); ret %= mod;
        ret = (ret - choose(subr, sub) + mod)%mod;
        lastEnd = j; lastBeg = i;
    }
    cout << ret;
    return 0;
}
/*
1000 9
1011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100101101110010110111001011011100
*/