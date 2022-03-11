//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;

#define pb push_back

#define f first
#define s second

bool prime(ll x){
    for(ll i = 2; i*i <= x; i++){
        if(x%i == 0) return false;
    }
    return true;
}

bool only(ll x, ll d){
    while(x%d == 0) x /= d;
    return x == 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll T; cin >> T;
    while(T--){
        ll x, d; cin >> x >> d;
        x /= d;
        if(x%d != 0){
            cout << "NO" << '\n'; continue;
        }
        
        ll times = 1;
        while(x%d == 0) {
            x /= d; times++;
        }
        if(prime(d) || times == 2){
            if(!prime(x)){
                cout << "YES" << '\n'; continue;
            }else{
                cout << "NO" << '\n'; continue;
            }
        }

        if(!prime(x) || times >= 4){
            cout << "YES" << '\n'; continue;
        }
        ll ok = 0;
        for(ll i = 2; i*i <= d; i++){
            if(d%i) continue;
            ok = ok || (x * i)%d != 0;
            ok = ok || (x * d / i)%d != 0;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }    
    return 0;
}
