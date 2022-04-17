//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

vector<int> consider(1e5 + 100);

struct DSU{
    vector<int> par, sz, special;
    DSU(int n){
        par.resize(n); sz.resize(n);
        for(int i = 0; i<n; i++) {
            par[i] = i; sz[i] = 1; special.pb(consider[i]);
        }
    }

    int root(int u){
        if (par[u] != u) par[u] = root(par[u]);
        return par[u];
        // return par[u] == u ? u : par[u] = root(par[u]);
    }

    void unite(int u, int v){
        int ru = root(u); int rv = root(v);
        if(ru == rv) return;
        if(sz[rv] > sz[ru]) swap(ru, rv);
        sz[ru] += sz[rv];
        special[ru] = special[ru] || special[rv];
        par[rv] = ru;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, M; cin >> N >> M;
    vector<array<int, 3>> edges(M);
    for(int i = 0; i<M; i++){
        int u, v, w; cin >> u >> v >> w; --u, --v;
        edges[i] = {u, v, w};
    }
    int Q; cin >> Q;
    vector<int> ret(Q); fill(ret.begin(), ret.end(), 2);
    vector<pii> queries(Q);
    for(int i = 0; i<Q; i++){
        int u, v; cin >> u >> v; --u, --v; queries[i] = pii(u, v);
    }
    
    DSU ones(N);
    for(auto j : edges){
        if((j[2]&1) == 1){
            ones.unite(j[0], j[1]);
        }
    }
    
    for(auto j : edges){
        if((j[2]&1) == 0){
            consider[j[0]] = consider[j[1]] = 1;
        }
    }
    vector<int> reach(N);
    for(int i = 0; i<30; i++){
        DSU cur(N);
        for(auto j : edges){
            if((j[2]>>i)&1){
                cur.unite(j[0], j[1]);
            }
        }
        for(int j = 0; j<Q; j++){
            if(cur.root(queries[j].f) == cur.root(queries[j].s)){
                ret[j] = 0;
            }
        }
        if(i == 0) continue;
        for(int j = 0; j<N; j++){
            reach[j] = reach[j] || cur.special[cur.root(j)];
        }
    }
    for(int i = 0; i<Q; i++){
        if(ret[i] == 0) continue;
        if(reach[queries[i].f]) ret[i] = 1;
    }
    for(int i : ret) cout << i << '\n';
    return 0;
}
