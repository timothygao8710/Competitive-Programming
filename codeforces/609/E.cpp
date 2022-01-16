//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

const int maxn = 5e5;
vector<int> adj[maxn];
int lift[23][maxn]; //change 
int height[maxn], vals[maxn];
int N, M, u, v;

void init(int u, int p = 0, int h = 0){
    height[u] = h;
    for(int n : adj[u]){
        if(n != p) init(n, u, h+1);
    }
}

int jump(int u, int k){ //view k in binary
    for(int i = 0; i<23; i++){
        if((k >> i) & 1){
            u = lift[i][u];
        }
    }
    return u;
}

int lca(int u, int v){
    if(height[v] > height[u]) swap(u, v);
    u = jump(u, height[u] - height[v]);
    assert(height[u] == height[v]);
    if(u == v) {
        return u;
    }
    // cout << u << " " << v << endl;
    for(int i = 22; i>=0; i--){ //jump pows strictly decrease
        if(lift[i][u] != lift[i][v]){
            // cout << i << " " << lift[i][u] <<  " " << lift[i][v] << endl;
            u = lift[i][u]; v = lift[i][v];
        }
    }
    return lift[0][u];
}

struct DSU{
    vector<int> par;
    DSU(int n){
        par.reserve(n);
        for(int i = 0; i<n; i++) {
            par.pb(i);
        }
    }

    int root(int u){
        return par[u] == u ? u : par[u] = root(par[u]);
    }

    void unite(int u, int v){ //can optimize if TLE
        par[v] = u;
    }

};

bool cmp(array<int, 4> a, array<int,4> b){
    return a[2] < b[2];
}

int main(){
    for(int i = 0; i<23; i++) lift[i][0] = 0;
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M; int idx = N+1;
    DSU dsu(2*N); int ret[M];
    array<int, 4> edges[M];
    for(int i = 0; i<M; i++){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2]; edges[i][3] = i;
    }
    ll sum = 0;
    sort(edges, edges+M, cmp);
    for(auto i : edges){
        u = dsu.root(i[0]); v = dsu.root(i[1]);
        if(u == v) continue;
        vals[idx] = i[2]; sum += i[2];
        adj[idx].pb(u); adj[idx].pb(v); 
        dsu.unite(idx, u); dsu.unite(idx, v); 
        // cout << idx << " " << u << endl;
        // cout << idx << " " << v << endl;
        lift[0][u] = idx; lift[0][v] = idx;
        idx++;
        assert(idx <= 2*N);
    }
    for(int i = 1; i<23; i++){
        for(int j = 1; j<idx; j++){
            lift[i][j] = lift[i-1][lift[i-1][j]];
        }
    }
    init(idx-1);
    for(int i = 0; i<M; i++){
        ret[edges[i][3]] = edges[i][2] - vals[lca(edges[i][0], edges[i][1])];
        lca(edges[i][0], edges[i][1]);
    }
    for(int i = 0; i<M; i++){
        cout << (sum + ret[i]) << "\n";
    }
    return 0;
}
