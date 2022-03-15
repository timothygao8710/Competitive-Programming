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
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        set<ll> all;
        ll num = 1, mn = 1e14, mx = 0;
        for(int i = 0; i<N; i++){
            ll a; cin >> a;
            mn = min(a, mn); mx = max(mx, a);
            all.insert(a);
        }
        num = mn * mx;
        // if(all.count(num)){
        //     cout << num*mn << '\n'; continue;
        // }
        int ok = 1;
        for(ll j = 2; j*j<=num; j++){
            if(num%j != 0) continue;
            ok = ok && all.count(num/j);
            ok = ok && all.count(j);
            if(!ok) break;
            all.erase(j);
            all.erase(num/j);
        }
        ok = ok && all.empty();
        if(!ok){
            cout << -1 << '\n';
        }else{
            cout << num << '\n';
        }
    }    
    return 0;
}
