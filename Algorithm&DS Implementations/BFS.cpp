//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

//about time I create this

const int maxn = 1e3;
const int maxm = 1e3;
const int n = 2e5;

vector<int> adj[n];
int grid[maxn][maxm];

//NOTE: Edges are pair<ll, int>
vector<ll> dijkstra(int n, vector<pii> adj[], int u){
    vector<ll> ret(n); 
    fill(ret.begin(), ret.end(), -1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0, u));
    while(!pq.empty()){
        pii cur = pq.top(); pq.pop();
        if(ret[cur.s]!=-1) {
            continue;
        }
        ret[cur.s] = cur.f;
        for(auto n : adj[cur.s]){
            if(ret[cur.s]!=-1) {
                pq.push(pii(cur.f+n.f, n.s));
            }
        }
    }
    return ret;
}

vector<int> BFS(int u, int N){
    vector<int> dist(N, -1);
    queue<pii> bfs;
    bfs.push(pii(u, 0));
    while(!bfs.empty()){
        pii c = bfs.front(); bfs.pop();
        if(dist[c.f] != -1) continue;
        dist[c.f] = c.s;        
        for(int n : adj[c.f]){
            bfs.push(pii(n, c.s + 1));
        }
    }
    return dist; //no visit -> -1
}

vector<int> multiBFS(vector<vector<int>>& adj, vector<int>& starts, int N){
    vector<int> dist(N, -1);
    queue<pii> bfs;
    for(int u : starts) bfs.push(pii(u, 0));
    while(!bfs.empty()){
        pii c = bfs.front(); bfs.pop();
        if(dist[c.f] != -1) continue;
        dist[c.f] = c.s;        
        for(int n : adj[c.f]){
            bfs.push(pii(n, c.s + 1));
        }
    }
    return dist; //no visit -> -1
}

vector<int> multiBFS(vector<int>& starts, int N){
    vector<int> dist(N, -1);
    queue<pii> bfs;
    for(int u : starts) bfs.push(pii(u, 0));
    while(!bfs.empty()){
        pii c = bfs.front(); bfs.pop();
        if(dist[c.f] != -1) continue;
        dist[c.f] = c.s;        
        for(int n : adj[c.f]){
            bfs.push(pii(n, c.s + 1));
        }
    }
    return dist; //no visit -> -1
}

int rDir[8] = {1, -1, 0, 0, -1, 1, -1, 1};
int cDir[8] = {0, 0, 1, -1, 1, 1, -1, -1};

int coordToNode(int u, int v, int M){
    return u * M + v;
}

pii nodeToCoord(int u, int M){
    return pii(u/M , u%M);
}

vector<vector<int>> gridToGraph(vector<vector<int>> grid, int N, int M){
    vector<vector<int>> gadj(N * M); //grid adjacency-list
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            for(int d = 0; d<4; d++){
                int dR = i + rDir[d], dC = j + cDir[d];
                if(dR < 0 || dC < 0 || dR >= N || dC >= M) continue;
                gadj[coordToNode(i, j, M)].pb(coordToNode(dR, dC, M));
            }
        }
    }
    return gadj;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    //https://leetcode.com/problems/01-matrix/



    auto updateMatrix = [&] (vector<vector<int>>& mat) {
        int N = mat.size(), M = mat[0].size();
        vector<int> starts;
        for(int i = 0; i<N; i++){
            for(int j =0; j<M; j++){
                if(mat[i][j] == 0) starts.pb(coordToNode(i, j, M));
            }
        }
        vector<vector<int>> adj = gridToGraph(mat, N, M);
        vector<int> ret = multiBFS(adj, starts, N * M);
        vector<vector<int>> grid(N, vector<int>(M));
        for(int i = 0; i<N*M; i++){
            pii cur = nodeToCoord(i, M);
            grid[cur.f][cur.s] = ret[i];
        }
        return grid;
    };

    return 0;
}
