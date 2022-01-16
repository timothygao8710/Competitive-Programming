//Author: timg8710

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
        assert(ru != rv);
        if(sz[rv] > sz[ru]) swap(ru, rv);
        sz[ru] += rv;
        par[rv] = ru;
    }

};

bool cmp(array<int, 3> a, array<int,3> b){
    return a[2] < b[2];
}

int main(){
    //both kruskals and prims, just on idea that same weights, same components is bad
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, M; cin >> N >> M;
    DSU dsu(N);
    array<int, 3> edges[M];
    
    for(int i = 0; i<M; i++){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    sort(edges, edges+M, cmp);

    int ret = 0;
    for(int i = 0; i<M;){
        int j = i;
        vector<pii> links;
        while(j < M && edges[i][2] == edges[j][2]){
            int a = dsu.root(edges[j][0]-1), b = dsu.root(edges[j][1]-1);
            if(a != b) {
                links.pb(pii(min(a,b), max(a,b)));
            }   
            j++;
        }
        for(auto k : links){
            if(dsu.root(k.f) == dsu.root(k.s)){
                ret++;
            }else{
                dsu.unite(k.f, k.s);
            }
        }
        i = j;
    }
    cout << ret;
    return 0;
}
