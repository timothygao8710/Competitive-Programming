//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

struct DSU{
    vector<int> par, sz;
    DSU(int n){
        par.reserve(n); sz.reserve(n);
        for(int i = 0; i<n; i++) {
            par.pb(i); sz.pb(1);
        }
    }

    int root(int u){
        return par[u] == u ? u : par[u] = root(par[u]);
    }

    void unite(int u, int v){
        int ru = root(u); int rv = root(v);
        if(ru == rv) return;
        if(sz[rv] > sz[ru]) swap(ru, rv);
        sz[ru] += sz[rv];
        par[rv] = ru;
    }

};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q, u, v, t;
    cin >> n; cin >> q;
    DSU dsu(n+1);
    for(int i = 0; i<q; i++){
        cin >> t; cin >> u; cin >> v;
        if(t){
            cout << ((int)(dsu.root(u) == dsu.root(v))) << endl;
        }else{
            dsu.unite(u, v);
        }
    }
    return 0;
}
