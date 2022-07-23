//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second
//Tarjan's DFS Tree
const int maxn = 2e5 + 100;
vector<int> adj[maxn];
vector<int> comp[maxn];
int dep[maxn], par_scc[maxn], vis_scc[maxn];
//vis 0: unvisited
//vis 1: visited from current dfs - cycle found
//vis 2: visited from different dfs - stop there
stack<int> st_scc;

void dfs_scc(int u, int d=0){
    vis_scc[u] = 1;
    dep[u] = d;
    for(int n : adj[u]){
        if(vis_scc[n] == 2) continue;
        while(!st_scc.empty() && dep[st_scc.top()] <= dep[n]){
            par_scc[st_scc.top()] = u;
            st_scc.pop();
        }
    }
    st_scc.push(u);
    for(int n : adj[u]){
        if(vis_scc[n] == 0) dfs_scc(n, d+1);
    }
    if(!st_scc.empty() && st_scc.top() == u) st_scc.top();
    vis_scc[u] = 2;
}

int root_scc(int u){
    return par_scc[u] == u ? u : par_scc[u] = root_scc(par_scc[u]);
}

void SCC(int N){
    for(int i = 0; i<N; i++) par_scc[i] = i;
    for(int i = 0; i<N; i++){
        assert(vis_scc[i] != 1);
        if(vis_scc[i] == 0) {
            dfs_scc(i);
        }
    }

    vector<int> inSCC(N);
    for(int i = 0; i<N; i++) {
        if(par_scc[i] == i) inSCC[i] = i;
        root_scc(i);
    }

    set<pii> dupedges;
    for(int i = 0; i<N; i++){
        for(int j : adj[i]){
            int u = par_scc[i], v = par_scc[j];
            if(u != v && !dupedges.count(pii(u, v))){
                // cout << u << " a " << v << endl;
                assert(!dupedges.count(pii(v, u)));
                comp[u].pb(v);
                dupedges.insert(pii(u, v));
            }
        }
    }
}

int main(){
    cout << (1<<30) << endl;
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int N, M; cin >> N >> M;
    for(int i = 0; i<M; i++){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
    }
    SCC(N);
    for(int i = 0; i<N; i++){
        cout << i << " is part of " << par_scc[i] << endl;
    }
    return 0;
}
/*
5 7
0 1
1 2
2 0
0 3
3 2
3 4
4 5
*/