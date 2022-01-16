//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second
const int mod = 998244353;

ll binpow(ll base, ll pow)
{
    if (pow == 0) return 1;
    ll half = binpow(base, pow / 2);
    ll ret = (half * half) % mod;
    if (pow % 2 == 1) ret *= base;
    return ret%mod;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T, N, u; cin >> T;
    while(T--){
        int last = 0, zeroes = 0, ps = 0;
        cin >> N; string s; cin >> s;
        for(int i =0; i<N; i++){
            if(s[i] == '0'){
                zeroes++; last = 0;
            }else{
                if(last == 1){
                    ps++; last = 0;
                }else{
                    last = 1;
                }
            }
        }
        //put 0s between pairs
        if(zeroes > ps) swap(zeroes, ps);
        ll ret = 1, inv = 1;
        for(int i = zeroes+ps; i>ps; i--){
            ret *= i; ret %= mod;
        }
        for(int i = 1; i<=zeroes; i++){
            inv *= i; inv %= mod;
        }
        cout << (ret * binpow(inv, mod-2))%mod << '\n';
    }    
    return 0;
}
