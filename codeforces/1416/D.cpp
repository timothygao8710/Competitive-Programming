//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define pb push_back
 
#define f first
#define s second


//dsu + euler tour + sgt

const int maxn = 2e5+24;
const int treesz = 5e5+3434;

pii t[4*treesz];
pii cmb(pii a, pii b){
    return a.f > b.f ? a : b;
}
void build(vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = pii(a[tl], tl);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = cmb(t[v*2], t[v*2+1]);
    }
}
//not sum, max
pii sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return pii(0,0);
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return cmb(sum(v*2, tl, tm, l, min(r, tm))
           , sum(v*2+1, tm+1, tr, max(l, tm+1), r));
}
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = pii(new_val, pos);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = cmb(t[v*2] , t[v*2+1]);
    }
}

//each node, plus auxillary for each edge
int idx = -1;
vector<int> tour, edge(treesz); //euler tour stuff
vector<int> adj[treesz]; vector<int> par(treesz); vector<int> qs[treesz]; vector<int> to(treesz);//reconstruction stuff
vector<int> vals(maxn);
set<int> vis;
int root(int u){
    return par[u] == u ? u : par[u] = root(par[u]);
}

void construct(int u, int N, int p=0){
    int temp = ++idx; tour.pb(u <= N ? vals[u] : 0); to[temp] = u;
    // cout << u<< " " << idx << endl;
    assert(!vis.count(u)); vis.insert(u);
    assert(adj[u].size() <= 3);
    for(int n : adj[u]){
        if(n == p) continue;
        construct(n, N, u);
    }
    edge[temp] = idx;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    for(int i = 0; i<treesz; i++) par[i] = i;
    int N, M, Q; cin >> N >> M >> Q;    
    for(int i = 1; i<=N; i++) {
        cin >> vals[i];
    }
    vector<pii> helper; helper.reserve(N+M);
    vector<pii> edges(M); 
    for(int i = 0; i<M; i++){
        cin >> edges[i].f >> edges[i].s;
    }
    for(int i = 0; i<Q; i++){
        int t, u; cin >> t >> u;
        if(t == 1){
            helper.pb(pii(-1, u));
        }else{
            --u;
            helper.pb(edges[u]); edges[u].f = 0;
        }
    }
    for(int i = 0; i<M; i++){
        if(edges[i].f) helper.pb(edges[i]);
    }
    vector<int> ret; ret.reserve(Q);
    int idx = N+1;
    reverse(helper.begin(), helper.end());
    for(pii i : helper){
        if(i.f == -1){
            // cout << root(i.s) << endl;
            qs[root(i.s)].pb(ret.size()); ret.pb(-1);
        }else{
            int u = root(i.f), v = root(i.s);
            adj[idx].pb(u); if(u != v) adj[idx].pb(v); 
            par[u] = par[v] = idx; idx++;
        }
    }
    assert(helper.size() == ret.size() + M);
    for(int i = idx-1; i>=1; i--) {
        if(!vis.count(i)){
            // cout << i << endl;
            construct(i, N);//graph is not connected by default...-_-
        } 
    }
    // cout << tour.size();
    assert(tour.size() == N+M);
    build(tour, 1, 0, N+M-1);

    for(int i = 0; i<N+M; i++){
        // cout << i << endl;
        reverse(qs[to[i]].begin(), qs[to[i]].end());
        for(int j : qs[to[i]]){
            // cout << j << endl;
            pii c = sum(1, 0, N+M-1, i, edge[i]);
            ret[j] = c.f;
            update(1, 0, N+M-1, c.s, 0);
        }
    }
    for(int i = ret.size()-1; i>=0; i--){
        cout << ret[i] << '\n';
    }
    return 0;
}
