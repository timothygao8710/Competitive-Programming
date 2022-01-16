/*
With sqrt decomp.
Theme: One algorithm is directly proportional to size, while the other is inversely proportional to size
(where size is the size of the chunk)

Inspired by CPH handbook section on sqrt algos
We do batching by sqrt(n), basically the same idea as the black/white cell example on CPH
*/

//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define pb push_back
 
#define f first
#define s second

const int maxn = 1e5+7;
int lift[18][maxn];
int height[maxn], color[maxn], dists[maxn];
vector<int> adj[maxn];

void dfs(int u, int p = 0, int h = 0){
    height[u] = h;
    lift[0][u] = p;
    for(int i = 1; i<=17; i++){
        lift[i][u] = lift[i-1][lift[i-1][u]];
    }
    for(int n : adj[u]){
        if(n == p) continue;
        dfs(n, u, h+1);
    }
}

int jump(int u, int k){ //view k in binary
    for(int i = 0; i<19; i++){
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
    for(int i = 17; i>=0; i--){ //jump pows strictly decrease
        if(lift[i][u] != lift[i][v]){
            u = lift[i][u]; v = lift[i][v];
        }
    }
    return lift[0][u];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, u, v, t; cin >> n >> m;
    int chunk = sqrt(n);
    memset(color, 0, sizeof(color));
    memset(lift[0], 0, sizeof(lift[0]));
    color[1] = 1;
    for(int i = 0; i<n-1; i++){
        cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }   

    dfs(1);

    int idx = 0;
    for(int i = 0; i*chunk < m; i++){
        memset(dists, -1, sizeof(dists));
        queue<pii> bfs;
        for(int j = 1; j<=n; j++){
            if(color[j]) bfs.push(pii(j, 0));
        }
        while(!bfs.empty()){
            pii cur = bfs.front(); bfs.pop();
            if(dists[cur.f] != -1) continue;
            dists[cur.f] = cur.s;
            for(int n : adj[cur.f]){
                bfs.push(pii(n, cur.s+1));
            }
        }
        vector<int> buffer;
        for(int j = 0; j<chunk && idx < m; idx++, j++){
            cin >> t >> u; 
            if(t-1){
                //print dist : lca w/ bin lift
                for(int k : buffer){
                    dists[u] = min(dists[u], height[k] + height[u] - 2*height[lca(k, u)]);
                }
                cout << dists[u] << "\n";
            }else{
                buffer.pb(u);
                color[u] = 1;
            }
        }
    }
    return 0;
}

