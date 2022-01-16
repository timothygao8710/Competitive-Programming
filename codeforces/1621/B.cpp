//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;

#define pb push_back

#define f first
#define s second

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        ll single = 0;
        pii low = pii(1e9+9, 0), hi = pii(-1, 0);
        for(int i = 0; i<N; i++){
            ll l, r, c; cin >> l >> r >> c; 
            int f = 0;
            if(l < low.f || (l == low.f && low.s > c)){
                if(l < low.f) single = 1e14;
                low = pii(l, c); f++;
            }
            if(r > hi.f || (r == hi.f && hi.s > c)){
                if(r > hi.f) single = 1e14;
                hi = pii(r, c); f++;
            }
            if(l == low.f && r == hi.f) {
                single = min(single, c);
            }
            cout << min(single, low.s + hi.s) << '\n';
        }
    }    
    return 0;
}
