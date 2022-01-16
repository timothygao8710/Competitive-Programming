//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define pb push_back
 
#define f first
#define s second

int xDir[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int yDir[8] = {1, -1, 0, 0, -1, 1, -1, 1};

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
//CHANGE THE FUCKING TEMPLATES
const int maxn = 2e4 + 9;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, M, K; cin >> N >> M >> K;
    map<pii, int> mp; vector<pii> tot;

    vector<pii> adj[K+2+N+M];
    int xst = K+2, yst = xst + N;
    // mp[pii(N-1, M-1)] = K+1; 
    // tot.pb(pii(N-1, M-1));
    int has = 0;
    for(int i = 1; i<=K; i++){
        pii a; cin >> a.f >> a.s; a.f--; --a.s;
        if(a.f == N-1 && a.s == M-1){
            has = 1;
        }
        tot.pb(a); mp[a] = i;
    }   

    for(pii i : tot){
        int c = mp[i];
        for(int j = 0; j<4; j++){
            int n = mp[pii(i.f + xDir[j], i.s + yDir[j])];
            if(n != 0){
                adj[c].pb(pii(0, n)); adj[n].pb(pii(0, c));
            }
        }
        for(int j = -1; j<=1; j++){
            if(j + i.f >= 0 && j + i.f < N){
                adj[xst + i.f + j].pb(pii(1, c));
                adj[c].pb(pii(1, xst + i.f + j));
            }
            if(j + i.s >= 0 && j + i.s < M){
                adj[yst + i.s + j].pb(pii(1, c));
                adj[c].pb(pii(1, yst + i.s + j));
            }
        }
    }
    vector<ll> ret = dijkstra(K+2+N+M, adj, mp[pii(0,0)]);
    int a = ret[mp[pii(N-1, M-1)]], b = ret[xst + N - 1], c = ret[yst + M - 1];
    if(a != -1){
        cout << (a/2); return 0;
    }
    if(b == -1 && c == -1){
        cout << -1; return 0;
    }
    
    cout <<(
        (min(
            b == -1 ? 1e9 : b,
            c == -1 ? 1e9 : c
        )+1)/2
    );
    return 0;
}