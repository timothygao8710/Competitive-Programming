//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
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
        sz[ru] += sz[rv]; sz[rv] = 0;
        par[rv] = ru;
    }

};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, D; cin >> N >> D;
    DSU dsu(N); int moves = 0;
    while(D--){
        int x, y; cin >> x >> y; --x, --y;
        if(dsu.root(x) == dsu.root(y)){
            moves++;
        }else{
            dsu.unite(x, y);
        }
        // cout << "MOVES: " << moves << endl;
        vector<int> temp;
        for(int i = 0; i<N; i++){
            if(dsu.root(i) == i) temp.pb(dsu.sz[i]);
            // cout << dsu.sz[i] << endl;
        }
        sort(temp.begin(), temp.end()); int ret = 0;
        for(int i = temp.size()-1; i>=max(0, (int)temp.size()-1-moves); i--){
            ret += temp[i];
        }
        cout << ret-1 << '\n';
    }
    return 0;
}
