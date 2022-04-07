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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    vector<int> inDeg(N);
    for(int i = 0; i<N-1; i++){
        int u, v; cin >> u >> v; --u, --v;
        inDeg[u]++, inDeg[v]++;
        // cout << inDeg[u] << " " << inDeg[v] << endl;
    }
    int leaf = 0;
    for(int i = 0; i<N; i++){
        
        if(inDeg[i] == 1) leaf++;
    }
    ll ret = (ll)(N-leaf) * binpow(2, N-leaf); ret %= mod;
    // cout << ret << endl;
    ret += leaf * binpow(2, N - leaf + 1); ret %= mod;
    cout << ret;
    return 0;
}
