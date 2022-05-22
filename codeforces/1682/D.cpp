//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second
//took me way too long to find the solution -_-
const int maxn = 2e5 + 100;
vector<pii> ret;

struct DSU{
    vector<int> par, sz;
    vector<pii> edges;
    DSU(int n){
        par.reserve(n); sz.reserve(n);
        for(int i = 0; i<n; i++) {
            par.pb(i); sz.pb(1);
            edges.pb(pii(i, i));
        }
    }

    int root(int u){
        return par[u] == u ? u : par[u] = root(par[u]);
    }

    void unite(int u, int v){
        int ru = root(u); int rv = root(v);
        if(ru == rv) return;
        ret.pb(pii(edges[ru].s, edges[rv].f));
        pii a = pii(edges[ru].f, edges[rv].s);
        if(sz[rv] > sz[ru]) swap(ru, rv);
        sz[ru] += sz[rv];
        par[rv] = ru;
        edges[ru] = a;
    }

};

int mark[maxn];
int vis[maxn];
int points[maxn][2];

void con(int u, int v){
    ret.pb(pii(points[u][mark[u]], points[v][mark[v]]));
    if(mark[u] == 0) mark[u] = 1;
    if(mark[v] == 0) mark[v] = 1;
}

void solve(){
    int N; cin >> N;
    string str; cin >> str;

    int odds = 0;
    for(int i = 0; i<N; i++){
        odds += str[i] == '1';
    }

    if(odds%2 || odds == 0){
        cout << "NO" << '\n'; return; //2*(N-1)
    }

    if(odds == N){
        cout << "YES" << '\n';
        for(int i = 2; i<=N; i++){
            cout << 1 << " " << i << '\n';
        }
        return;
    }

    ret.clear();
    for(int i = 0; i<N; i++){
        mark[i] = vis[i] = 0; 
        points[i][0] = points[i][1] = i;
    }

    DSU dsu(N);
    for(int i = 0; i<N; i++){
        if(str[i] == '0' && str[(i+1)%N] == '0'){
            dsu.unite(i, (i+1)%N);
        }
    }

    // cout << "POINTS :" << endl;
    set<int> pars;
    int root = -1;
    for(int i = 0; i<N; i++){
        if(str[i] == '0') {
            int p = dsu.root(i);
            root = p; pars.insert(p);
            points[p][0] = dsu.edges[p].f;
            points[p][1] = dsu.edges[p].s;
        }
        // cout << p << " " << points[p][0] << " " << points[p][1] << endl;
    }

    
    // for(int i : pars){
    //     if(i != root){
    //         con(i, root);
    //     }
    // }

    // cout << endl;
    for(int i = 0; i<N; i++){
        if(str[i] == '1' && str[(i+1)%N] == '0'){            
            int p = dsu.root((i+1)%N);
            // cout << "HERE " << p << endl;
            // if(vis[p]) continue;
            // vis[p] = 
            vis[i] = 1;
            con(i, p);
        }
    }
    assert(mark[root] == 1);
    for(int i = 0; i<N; i++){
        if(!vis[dsu.root(i)] && dsu.root(i) != root){
            // if(str[i] == '0'){
            con(dsu.root(i), root);
            vis[dsu.root(i)] = 1; 
        }
    }

    cout << "YES" << '\n';
    for(pii i : ret){
        cout << (i.f + 1) << " " << (i.s + 1) << '\n';
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



 
