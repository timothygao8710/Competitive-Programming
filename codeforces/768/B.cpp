//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;
 
#define pb push_back
 
#define f first
#define s second

map<ll, pii> sz;
//sz : 1s
pii precomp(ll n){
    if(sz[n].f == 0) {
        pii next = precomp(n/2);
        sz[n] = pii(2*next.f + 1, 2*next.s + n%2);
    }
    // cout << n << " " << sz[n].f << " " << sz[n].s << endl;
    return sz[n];
}

ll find(ll n, ll l, ll r){
    if(l > r) return 0;
    assert(sz[n].first != 0);

    // if(n != 0) cout << n << " " << l << " " << r << " " << sz[n].f << endl;
    if(l == 1 && r == sz[n].f){
        return sz[n].s;
    }else{
        ll ret = (l <= sz[n].f/2 + 1 && r >= sz[n].f/2 + 1 && n%2);
        return (
            ret + find(n/2, l, min(r, sz[n].f/2)) + 
            find(n/2, max(l, sz[n].f/2 + 2) - sz[n].f/2 - 1, r - sz[n].f/2 - 1)
        );
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, l, r;
    cin >> n >> l >> r;
    sz[0] = pii(1, 0);
    sz[1] = pii(1,1);
    precomp(n);
    cout << find(n, l, r);
    return 0;
}
