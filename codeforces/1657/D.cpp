//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;

#define pb push_back

#define f first
#define s second

/*
troop: H_t, N * D_t
monster: H_m, D_m

H_m/(N*D_t) < H_t/D_m
H_m * D_m < N * (D_t * H_t)
*/


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, C; cin >> N >> C; ++C;
    vector<ll> best(C);
    for(int i = 0; i<N; i++){
        ll cost, damage, health; cin >> cost >> damage >> health;
        best[cost] = max(best[cost], damage * health);
    }
    for(int i = 1; i<C; i++){ //iterate in reverse should be same?
        ll am = best[i];
        for(int j = i; j<C; j+=i, am += best[i]){
            best[j] = max(best[j], am);
        }
    }
    map<ll, ll> mp; //value : cost, monotonic
    ll last = 0;
    for(int i = 1; i<C; i++){
        if(best[i] > last){
            last = best[i];
            mp[last] = i;
        }
    }
    int Q; cin >> Q;
    while(Q--){
        ll D, H; cin >> D >> H;
        ll val = D * H; //upperbound
        auto it = mp.upper_bound(val);
        if(it == mp.end()){
            cout << -1 << " ";
        }else{
            cout << ((*it).s) << " ";
        }
    }
    return 0;
}