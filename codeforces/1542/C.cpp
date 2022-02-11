//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

const int mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        ll N; cin >> N;
        ll cur = 1, ret = 0;
        for(ll i = 2; cur <= N; i++){
            ll nxt = lcm(cur, i);
            ret += i * (N/cur - N/nxt); ret %= mod;
            cur = nxt;
        }
        cout << ret << '\n';
    }    
    return 0;
}
