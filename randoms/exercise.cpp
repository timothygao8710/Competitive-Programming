//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;
 
#define pb push_back
 
#define f first
#define s second

void setIO(string s) { // the argument is the filename without the extension
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

const int maxn = 2e5+7; const int maxlog = 19;
ll dep[maxn], touch[maxn];
map<pii, ll> mp[maxn];
pii lift[maxlog][maxn];
vector<int> adj[maxn];
ll ret;

void init(int u, int p = 0, int h = 0){
    dep[u] = h; lift[0][u].f = p;
    lift[0][u].s = touch[u];
    for(int i = 1; i<maxlog; i++){
        lift[i][u].f = lift[i-1][lift[i-1][u].f].f;
        lift[i][u].s = lift[i-1][u].s + lift[i-1][lift[i-1][u].f].s;
    }
    for(int n : adj[u]){
        if(p != n) init(n, u, h+1);
    }
}

pii jump(int u, int k){ //view k in binary
    ll add = 0;
    for(int i = 0; i<maxlog; i++){
        if((k >> i) & 1){
            u = lift[i][u].f; add += lift[i][u].s;
        }
    }
    return pii(u, add);
}

int lca(int u, int v){
    if(dep[u] > dep[v]) swap(u, v);
    pii j = jump(v, dep[v] - dep[u]); v = j.f;
    assert(dep[u] == dep[v]);
    if(u == v) {
        ret += j.s - 1;
        return u;
    }
    ret += j.s;
    for(int i = maxlog-1; i>=0; i--){ //jump pows strictly decrease
        if(lift[i][u] != lift[i][v]){
            ret += lift[i][u].s + lift[i][v].s;
            u = lift[i][u].f; v = lift[i][v].f;
        }
    }
    ret += touch[u] + touch[v]-2;
    mp[lift[0][u].f][pii(min(u, v), max(u, v))]++;
    return 0;
}

long long choose2(int m)
{
	return (((long long) m)*(m-1))/2;
}

int main(){
    setIO("exercise");
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, M, u, v, r; cin >> N >> M; M = M-N+1;
    for(int i = 0; i<N-1; i++){
        cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    set<pii> rep;
    pii edges[M];
    for(int i = 0; i<M; i++){
        cin >> u >> v; edges[i] = pii(u, v);
        assert(rep.count(pii(u,v)) == 0); rep.insert(pii(u, v));
        touch[lca(u, v)]--; touch[u]++; touch[v]++;
    }
    ret = 0;
    //Edge Case: Up edges :(
    init(1);
    for(int i = 0; i<M; i++){
        lca(edges[i].f, edges[i].s);
    }
    // cout << ret << endl;
    for(int i = 1; i<=N; i++){
        for(auto j : mp[i]){
            // if(j.f == j.f)continue;
            ret -= choose2(j.s);
        }
        ret -= choose2(touch[i]);
        //edge: triple connect, a->b->c, we overcount b
    }
    cout << ret;
    return 0;
}
/*
3 4
1 2
1 3
2 3
2 3

5 7
1 2
2 3
1 4
4 5 
2 4
3 5
3 5

up edge:
3 4
1 2
2 3
3 1
2 1
*/