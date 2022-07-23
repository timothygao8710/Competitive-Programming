//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

struct HashedString{
    int moda = 1e9+7, modb = 1e9+9;
    ll base = 9973;

    vector<pii> poly; //a[i] + a[i] * x + a[i] * x^2 + a[i] * x^3 ...
    vector<pair<ll, ll>> pow;
    HashedString(int N, string str){
        poly.resize(N+1); pow.resize(N+1); pow[0].f = pow[0].s = 1;
        for(int i = 1; i<=N; i++) {
            pow[i].f = (pow[i-1].f * base)%moda;
            pow[i].s = (pow[i-1].s * base)%modb;
        }
        for(int i = N-1; i>=0; i--){
            poly[i].f = (poly[i+1].f*base + str[i])%moda;
            poly[i].s = (poly[i+1].s*base + str[i])%modb;
        }
    }

    //inclusive
    pii get(int l, int r){
        pii ret;
        ret.f = (poly[l].f - (poly[r+1].f*(pow[r-l+1].f)%moda) + moda) % moda;
        ret.s = (poly[l].s - (poly[r+1].s*(pow[r-l+1].s)%modb) + modb) % modb;
        return ret;
    }
};


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    string a, b; cin >> a >> b;
    int N = a.length(), M = b.length();
    HashedString large(M, b);
    vector<int> freq(26), run(26);
    for(int i = 0; i<N; i++){
        freq[a[i] - 'a']++;
    }
    set<pii> all;
    for(int i = 0; i<N; i++){
        run[b[i] - 'a']++;
    }
    if(freq == run) all.insert(large.get(0, N-1));
    for(int i = N; i<M; i++){
        run[b[i-N]-'a']--;
        run[b[i]-'a']++;
        if(freq == run) all.insert(large.get(i-N+1, i));
    }
    cout << all.size();
    return 0;
}
/*
aab
abababaa
*/