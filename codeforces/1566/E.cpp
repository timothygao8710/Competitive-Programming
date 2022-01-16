//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

const int maxn = 2e5 + 7;
vector<int> adj[maxn];
bool bud[maxn];
bool leaf[maxn];
int tot = 0, par = -1;


int root(int u, int p = 0){
    if(u == 0 && (int)(adj[u].size()) > 1) return u;
    if((int)(adj[u].size()) > 2){
        par = p;
        return u;
    } 
    for(int n : adj[u]){
        if(n != p) return root(n, u);
    }
    par = p;
    return u;
}

void assign(int u, int p){
    if((int)(adj[u].size()) == 1){ 
        leaf[u] = 1; tot++;
        return;
    }
    bool isBud = 0;
    int leaves = 0;
    for(int n : adj[u]){
        if(n == p) continue;
        assign(n, u);
        isBud = isBud || (!bud[n] || leaf[n]);
    }
    //cout << u << " " << isBud << endl;
    bud[u] = isBud;
    if(isBud){
        tot--;
    }else{
        tot++;
    }
}
/*
1
14
1 2
2 3
3 4
3 5
5 6
5 7
7 8
9 7
7 11
3 10
9 12
12 13
12 14
*/
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        tot = 0, par = -1;
        for(int i = 0; i<N; i++){
            adj[i].clear(); bud[i] = leaf[i] = 0;
        }
        for(int i = 0; i<N-1; i++){
            int u, v; cin >> u >> v; u--, v--;
            adj[u].pb(v); adj[v].pb(u);
        }
        int r = root(0);
        if(adj[r].size() == 1){
            cout << 1 << '\n'; continue;
        }
        //cout << r << endl;
        assign(r, par);
        if(bud[r]){
            tot++;
        }else{
            tot--;
        }
        //cout << tot << endl;
        int used = 0;
        for(int n : adj[r]){
            if(n == par) continue;
            if(!bud[n]) used = 1;
        }
        cout << tot + (used == 0) << '\n';
    }
    return 0;
}
