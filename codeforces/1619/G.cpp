//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

const int maxn = 2e5 + 234;
vector<int> adj[maxn];
vector<array<int, 3>> points(maxn);
vector<int> vis(maxn);

int dfs(int u){
    int ret = points[u][2]; vis[u] = 1;
    for(int n : adj[u]){
        if(!vis[n]) ret = min(ret, dfs(n));
    }
    return ret;
}

void solve(){
    int N, K; cin >> N >> K;
    for(int i = 0; i<=N+10; i++) adj[i].clear();

    map<int, vector<pii>> xs, ys;
    for(int i = 0; i<N; i++){
        vis[i] = 0;
        cin >> points[i][0] >> points[i][1] >> points[i][2];
        xs[points[i][0]].pb(pii(points[i][1], i));
        ys[points[i][1]].pb(pii(points[i][0], i));
    }
    for(auto col : xs){
        vector<pii> cur = col.s;
        sort(cur.begin(), cur.end());
        for(int i = 1; i<cur.size(); i++){
            if(cur[i].f - cur[i-1].f <= K){
                adj[cur[i].s].pb(cur[i-1].s);
                adj[cur[i-1].s].pb(cur[i].s);
            }
        }
    }
    for(auto row : ys){
        vector<pii> cur = row.s;
        sort(cur.begin(), cur.end());
        for(int i = 1; i<cur.size(); i++){
            if(cur[i].f - cur[i-1].f <= K){
                adj[cur[i].s].pb(cur[i-1].s);
                adj[cur[i-1].s].pb(cur[i].s);
            }
        }
    }
    vector<int> tot;
    for(int i = 0; i<N; i++){
        if(!vis[i]) tot.pb(dfs(i));
    }
    sort(tot.begin(), tot.end());
    // cout << "hooly" << endl;
    // for(int i : tot) cout << i << " ";
    // cout << endl;
    int idx = 0;
    
    for(int i = 0; i<tot.size(); i++){
        while(idx < tot.size() && tot[idx] <= i) idx++;
        if(tot.size() - idx <= i + 1){
            cout << i << '\n'; break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        solve();
    }    
    return 0;
}
