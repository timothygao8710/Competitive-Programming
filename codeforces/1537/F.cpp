//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define pb push_back
 
#define f first
#define s second

//The key idea here is that any two moves a -> b -> c is equal to redistributing the sum from a -> c
//note to self: look into how to clear adjacency list between test cases
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int c, T, N, M, u, v; cin >> T;    
    while(T--){
        ll sum = 0;
        cin >> N >> M;
        int wants[N+1];
        for(int i = 1; i<=N; i++) cin >> wants[i];
        for(int i = 1; i<=N; i++){
            cin >> c; wants[i] = c - wants[i];
            sum += wants[i];
        }
        vector<int> adj[N+1];
        for(int i = 0; i<M; i++){
            cin >> u; cin >> v;
            adj[u].pb(v); adj[v].pb(u);
        }
        if(sum%2){
            cout << "NO\n"; continue;
        }
        int vis[N+1]; memset(vis, -1, sizeof(vis));
        ll pars[] = {0,0}; 
        vector<pii> dfs; //node : par
        dfs.pb(pii(1, 0));
        while(!dfs.empty()){
            pii c = dfs.back(); dfs.pop_back();
            if(vis[c.f] != -1){
                if(vis[c.f] != c.s){
                    pars[0] = pars[1] = 0; break;
                }else{
                    continue;
                }
            }
            pars[c.s] += wants[c.f]; vis[c.f] = c.s;
            for(int n : adj[c.f]){
                dfs.pb(pii(n, c.s^1));
            }
        }
        if(pars[0] == pars[1]){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}
