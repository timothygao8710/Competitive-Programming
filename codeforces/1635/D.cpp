//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second
const int mod = 1e9+7;
ll binpow(ll base, ll pow)
{
    ll ret = 1;
    while(pow > 0){
        if(pow & 1) ret = (ret * base)%mod;
        base = (base * base)%mod;
        pow >>= 1;
    }
    return ret;
}

int gBit(ll x){
    for(int i = 34; i>=0; i--){
        if((x>>i)&1) return i;
    }
    // cout << x << endl;
    assert(false);
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, P; cin >> N >> P;
    
    int t = P+10000;
    vector<ll> fib(t), dp(t); fib[0] = fib[1] = 1;
    for(int i = 2; i<t; i++){
        fib[i] = (fib[i-1] + fib[i-2])%mod;
    }
    dp[0] = fib[0];
    for(int i = 1; i<t; i++) {
        dp[i] = (dp[i-1] + fib[i])%mod;
        // cout << dp[i] << endl;
    }
    ll ret = 0;
    set<ll> has;
    vector<ll> nums(N);
    for(int i = 0; i<N; i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    for(int j = 0; j<N; j++){
        ll a = nums[j]; ll og = a;
        while(a){
            if(a&1){
                a /= 2;
            }else{
                if((a%4) != 0){
                    break;
                }
                a /= 4;
            }
            if(has.count(a)) {
                og = -1; break;
            }
        }
        if(og == -1) continue;
        int b = gBit(og);
        if(b >= P) continue;
        has.insert(og);
        ret += dp[P-b-1]; ret %= mod;
    }
    cout << ret << '\n';
    return 0;
}

