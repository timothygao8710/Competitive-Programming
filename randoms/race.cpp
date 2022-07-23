#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;
 
#define pb push_back
 
#define f first
#define s second

const int maxn = 2e5+20;
vector<pii> adj[maxn];
unordered_map<ll, ll> info[maxn]; 
ll dist[maxn], height[maxn]; //define dist relative to root
int N, K, u, v; ll ret;

void dfs1(int u, int p, ll c, int h){
    info[u][c] = h; 
    dist[u] = c; height[u] = h;
    for(auto n : adj[u]){
        if(p == n.f) continue;
        dfs1(n.f, u, c + n.s, h + 1);
    }
}

void dfs(int u, int p){
    ll target = K + 2*dist[u];
    for(auto n : adj[u]){
        if(n.f == p) continue;
        dfs(n.f, u);
        if(info[n.f].size() > info[u].size()){
            swap(info[n.f], info[u]);
        }
        for(auto i : info[n.f]){
            if(info[u].find(target - i.f) != info[u].end()){
                ret = min(ret, info[u][target - i.f] + i.s - 2*height[u]);
            }
        }
        for(auto i : info[n.f]){
            if(info[u].find(i.f) == info[u].end()){
                info[u].insert(i);
            }else{
                info[u][i.f] = min(info[u][i.f], i.s);
            }
        }
    } 
}

//new to c++, feel free to give suggestions on how to improve code/make it easier to read
int best_path(int n, int k, int edges[][2], int weights[]){
    if(k == 1) return 0;
    N = n; K = k; ret = INT_MAX;
    for(int i = 0; i<n-1; i++){
        u = edges[i][0]; v = edges[i][1];
        adj[u].pb(pii(v, weights[i])); adj[v].pb(pii(u, weights[i]));
    }
    dfs1(0, -1, 0, 0);
    dfs(0, -1);
    return ret == INT_MAX ? -1 : ret;
}

// int main(){
//     cin >> N >> K;
//     int edges[N][2]; int weights[N];
//     for(int i = 0; i<N-1; i++){
//         cin >> u >> v;
//         edges[i][0] = u; edges[i][1] = v;
//     }
//     for(int i = 0; i<N-1; i++){
//         cin >> u; weights[i] = u;
//     }
//     cout << best_path(N, K, edges, weights);
// }
/*
11 12
0 1
0 2
2 3
3 4
4 5
0 6
6 7
6 8
8 9
8 10
3
4
5
4
6
3
2
5
6
7

4 3
0 1
1 2
1 3
1
2
4
*/