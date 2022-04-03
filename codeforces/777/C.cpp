//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

struct DSU{
    vector<int> par, sz;
    DSU(int n){
        par.reserve(n); sz.reserve(n);
        for(int i = 0; i<n; i++) {
            par.pb(i); sz.pb(1);
        }
    }

    int root(int u){
        return par[u] == u ? u : par[u] = root(par[u]);
    }

    void unite(int u, int v){
        int ru = root(u); int rv = root(v);
        if(ru == rv) return;
        if(sz[rv] > sz[ru]) swap(ru, rv);
        sz[ru] += sz[rv];
        par[rv] = ru;
    }

};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, M; cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M));
    vector<int> best(N); fill(best.begin(), best.end(), 1e9); best[0] = 0;
    // DSU dsu(N);
    for(int i = 0; i<N; i++) for(int j = 0; j<M; j++) cin >> grid[i][j];
    for(int i = 0; i<M; i++){
        int last = 0;
        for(int j = 1; j<N; j++){
            if(grid[j][i] < grid[j-1][i]) {
                last = j;
            }
            best[j] = min(best[j], last);
        }
    }
    int K; cin >> K;
    while(K--){
        int l, r; cin >> l >> r; --l, --r;
        cout << (best[r] <= l ? "Yes" : "No") << '\n';
    }
    return 0;
}
