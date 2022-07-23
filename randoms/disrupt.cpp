//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define pb push_back
 
#define f first
#define s second

const int maxn = 2e5+7; const int maxlog = 19;
int height[maxn], lift[maxlog][maxn], ret[maxn];

vector<int> out[maxn];
multiset<int> run[maxn];
vector<pii> in[maxn], adj[maxn];

void setIO(string s) { // the argument is the filename without the extension
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

void dfs(int u, int p = 0){
    multiset<int>& cur = run[u];
    for(auto n : adj[u]){
        if(n.f == p) continue;
        dfs(n.f, u); multiset<int>& next = run[n.f];
        ret[n.s] = next.empty() ? -1 : *next.begin();  //might be wrong
        if(cur.size() < next.size()) swap(next, cur);
        for(int i : next) cur.insert(i);
    }
    for(int i : out[u]) cur.erase(cur.find(i));
    for(auto i : in[u]){
        cur.insert(i.f); out[i.s].pb(i.f);
    }
}

void init(int u, int p = 0, int h = 0){
    height[u] = h; lift[0][u] = p;
    for(int i = 1; i<maxlog; i++){
        lift[i][u] = lift[i-1][lift[i-1][u]];
    }
    for(auto n : adj[u]){
        if(p != n.f) init(n.f, u, h+1);
    }
}

int jump(int u, int k){ //view k in binary
    for(int i = 0; i<maxlog; i++){
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
    for(int i = maxlog-1; i>=0; i--){ //jump pows strictly decrease
        if(lift[i][u] != lift[i][v]){
            u = lift[i][u]; v = lift[i][v];
        }
    }
    return lift[0][u];
}

int main(){
    setIO("disrupt");
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, M, u, v, w;
    cin >> N >> M;
    for(int i = 0; i<N-1; i++){
        cin >> u >> v;
        adj[u].pb(pii(v, i)); adj[v].pb(pii(u, i));
    }   
    init(1); 
    for(int i = 0; i<M; i++){
        cin >> u >> v >> w; int root = lca(u,v);
        if(root != u) in[u].pb(pii(w, root));
        if(root != v) in[v].pb(pii(w, root));
    }
    dfs(1);
    for(int i = 0; i<N-1; i++){
        cout << ret[i] << "\n";
    }
    return 0;
}
/*
4 1
1 2
3 2
4 2
1 3 1
*/