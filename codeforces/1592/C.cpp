//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

int ok = 0, sum = 0;
int K, N;
pii dfs(vector<vector<int>>& adj, vector<int>& vals, int u, int p = 0){
    pii ret(vals[u], 0); //sum : occ
    for(int n : adj[u]){
        if(n == p) continue;
        pii nxt = dfs(adj, vals, n, u);
        ret.f ^= nxt.f;
        ret.s += nxt.s;
    }
    ok = ok || (ret.s >= 2);
    if(ret.f == 0 && ret.s == 1) ok = 1;
    ret.s = ret.s || ret.f == sum;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        ok = 0;
        cin >> N >> K; --K;
        sum = 0;
        vector<int> vals(N+1);
        for(int i = 0; i<N; i++){
            cin >> vals[i+1]; sum ^= vals[i+1];
        }

        vector<vector<int>> adj(N+1, vector<int>());
        for(int i = 0; i<N-1; i++){
            int u, v; cin >> u >> v;
            adj[u].pb(v), adj[v].pb(u);
        }
        
        if(sum == 0){
            cout << "YES" << '\n'; continue;
        }
        if(K == 1){
            cout << "NO" << '\n'; continue;
        }
        dfs(adj, vals, 1);
        if(ok){
            cout << "YES" << '\n';
        }else{
            cout << "NO" << '\n';
        }
    }    
    return 0;
}
