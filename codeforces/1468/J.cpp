//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

struct DSU{
    vector<int> par, sz;
    int left = 0;
    DSU(int n){
        left = n;
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
        left--;
        if(sz[rv] > sz[ru]) swap(ru, rv);
        sz[ru] += sz[rv];
        par[rv] = ru;
    }

    bool con(){
        return left == 2;
    }

};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N, M, K; cin >> N >> M >> K;
        DSU dsu(N+1);
        vector<array<int, 3>> edges;
        for(int i = 0; i<M; i++){
            int u, v, w; cin >> u >> v >> w;
            edges.pb({w, u, v});
        }
        sort(edges.begin(), edges.end());
        ll ret = LLONG_MAX, run = 0;
        int idx = M;
        for(int i = 0; i<M; i++){
            if(edges[i][0] > K){
                idx = i; break;
            }
            dsu.unite(edges[i][1], edges[i][2]);
        }
        if(dsu.con() && idx-1 >= 0) ret = min(ret, (ll)K - edges[idx-1][0]);
        // cout << "X" << run << endl;
        for(int i = idx; i<M; i++){
            // cout << "W" << run << endl;
            ll add = 0;
            if(dsu.root(edges[i][1]) != dsu.root(edges[i][2])){
                add = edges[i][0] - K;
                dsu.unite(edges[i][1], edges[i][2]);
            }
            if(dsu.con()) {
                ret = min(ret, run + edges[i][0] - K);
                // cout << run << " " << (edges[i][0] - K) << endl;
            }
            run += add;
        }
        cout << ret << '\n';
    }    
    return 0;
}
