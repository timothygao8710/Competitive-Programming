//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll N, mod; cin >> N >> mod;
    ll fact[N+1]; fact[0] = 1;
    for(int i = 1; i<=N; i++){
        fact[i] = fact[i-1]*i; fact[i] %= mod;
    }
    ll ret = 0;
    for(int i = 1; i<=N; i++){
        ll cur = fact[i]; //given a length
        cur *= N-i+1; //how many starter numbers?
        cur %= mod;
        cur *= N-i+1; //how many places to put it?
        cur %= mod;
        cur *= fact[N-i]; //permuate the remaining
        cur %= mod;
        ret = (ret + cur)%mod;
    }
    cout << ret;
    return 0;
}
