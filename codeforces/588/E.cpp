//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

const int maxn = 1e5+69;

vector<int> adj[maxn], id[19][maxn];
int lift[19][maxn]; int height[maxn];
int sz = 10;
vector<int> res;

void comb(vector<int>& a, vector<int>& b){ //optimize later if nessesary
    a.insert(a.end(), b.begin(), b.end());
    sort(a.begin(), a.end());
    if(a.size() > sz) a.resize(sz);
}

void init(int u, int p=0, int h=0){
    height[u] = h; lift[0][u] = p;
    for(int i = 1; i<19; i++){
        lift[i][u] = lift[i-1][lift[i-1][u]];
        id[i][u] = id[i-1][u];
        comb(id[i][u], id[i-1][lift[i-1][u]]);
        // cout << u << " " << i << " " << id[i][u].size() << endl;
    }
    for(int n : adj[u]){
        if(n != p) init(n, u, h+1);
    }
}

int jump(int u, int k){ //view k in binary
    for(int i = 0; i<19; i++){
        if((k >> i) & 1){
            comb(res, id[i][u]);
            // cout << "jump " << i << " " << u << " " << id[i][u].size() << endl;
            u = lift[i][u];
        }
    }
    return u;
}

void lca(int u, int v){
    if(height[v] > height[u]) swap(u, v);
    u = jump(u, height[u] - height[v]);
    assert(height[u] == height[v]);
    
    if(u == v) {
        comb(res, id[0][u]);
        return;
    }
    for(int i = 18; i>=0; i--){ //jump pows strictly decrease
        if(lift[i][u] != lift[i][v]){
            // cout << id[i][u].size() << " " << id[i][v].size() << endl;
            comb(res, id[i][u]); comb(res, id[i][v]);
            u = lift[i][u]; v = lift[i][v];
        }
    }
    comb(res, id[0][u]); comb(res, id[1][v]);
}

int main(){
    for(int i = 0; i<19; i++){
        memset(lift[i], 0, sizeof(lift[i]));
    } //note to self: remove this, see what happens
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, M, Q, u, v;
    cin >> N >> M >> Q;
    for(int i = 0; i<N-1; i++){
        cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    for(int i = 0; i<M; i++){
        cin >> u;
        if(id[0][u].size() <= 10) id[0][u].pb(i);
    }
    init(1);
    for(int q =0; q<Q; q++){
        cin >> u >> v >> sz;
        lca(u, v);
        cout << res.size() << " ";
        for(int i : res){
            cout << (1+i) << " ";
        }
        res.clear();
        cout << "\n"; 
    }
    return 0;
}
