//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back

#define f first
#define s second

ll* dijkstra(int n, vector<pii> adj[], int u){
    ll* ret = new ll[n]; 
    fill(ret, ret+n, -1);
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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, u, v, w;
    cin >> n; cin >> m;
    vector<pii> adj[n+1];
    for(int i = 0; i<m; i++){
        cin >> u; cin >> v; cin >> w;
        adj[u].pb(pii(w, v));
    }
    ll* ret = dijkstra(n+1, adj, 1);
    for(int i = 1; i<=n; i++){
        cout << ret[i] << " ";
    }
    return 0;
}