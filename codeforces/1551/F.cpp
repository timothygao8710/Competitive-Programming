//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second


const ll mod = 1e9+7;
ll dp[2000];

int binpow(ll base, ll pow)
{
    if (pow == 0) return 1;
    ll half = binpow(base, pow / 2);
    ll ret = (half * half) % mod;
    if (pow % 2 == 1) ret *= base;
    return ret%mod;
}

ll choose(ll a, ll b){ //big : small
    if(a<0||b<0||a<b) return 0;
    ll ret = dp[a]; ll denom = (dp[a-b]*dp[b])%mod;
    ret *= binpow(denom, mod-2); ret %= mod;
    return ret;
}

int main(){
    dp[0] = 1;
    for(int i = 1; i<2000; i++){
        dp[i] = (dp[i-1] * i) % mod;
    }
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T, N, K, u, v;
    cin >> T;
    while(T--){
        cin >> N >> K; ll ret = 0;
        vector<int> adj[N+1];
        for(int i = 0; i<N-1; i++){
            cin >> u >> v;
            adj[u].pb(v); adj[v].pb(u);
        }
        for(int i = 1; i<=N; i++){
            if(adj[i].size() < K) continue;
            vector<pii> bfs; vector<int> vis; vis.resize(N+1); vis[i] = 1;
            for(int n : adj[i]){
                bfs.pb(pii(n, n));
            }
            while(!bfs.empty()){
                unordered_map<int, int> sz;
                vector<pii> step;
                for(pii j : bfs){
                    sz[j.s]++; vis[j.f] = 1;
                    for(int n : adj[j.f]){
                        if(!vis[n]) step.pb(pii(n, j.s));
                    }
                }
                if(sz.size() < K){
                    break; //later use to debug in conjuction with adjsz < K
                } 
                int s = sz.size();
                vector<int> all;
                for(auto i : sz){
                    all.pb(i.s); 
                    // cout << i.s << " ";
                }
                // cout << endl;
                ll dp[s+1][K+1];
                for(int i = 0; i<=s; i++){
                    for(int j = 0; j<=K; j++){
                        dp[i][j] = (j == 0);
                    }
                }
                
                for(int i = 1; i<=s; i++){
                    for(int j = 1; j<=K; j++){
                        dp[i][j] = dp[i-1][j];
                        if(j != 0) dp[i][j] += dp[i-1][j-1] * all[i-1];
                        dp[i][j] %= mod;
                        // cout << dp[i][j] << " ";
                    }
                    // cout << endl;
                }
                ret += dp[s][K]; ret %= mod;
                // cout << ret << endl;
                swap(step, bfs);
            }   
        }
        cout << (K == 2 ? (N)*(N-1)/2 : ret) << '\n';
    }
    return 0;
}
/*
1
5 3
1 2
2 3
2 4
4 5
*/