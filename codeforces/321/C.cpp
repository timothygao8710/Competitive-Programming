//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second


const int maxn = 2e5 + 8;
vector<int> adj[maxn];
char type[maxn];
int csz[maxn], cvis[maxn], cpar[maxn]; //csz[u] will change overtime

struct centroidDecomp{
    int initsz(int u, int p = 0){ //finds the sz of current group/component
        csz[u] = 1;
        for(int n : adj[u]){
            if(!cvis[n] && n != p) csz[u] += initsz(n, u);
        }
        return csz[u];
    }
 
    int init(int u, int compsz, int p = 0, char d = 'A'){
        for(int n : adj[u]){
            if(n != p && !cvis[n] && csz[n] > compsz/2){
                return init(n, compsz, u, d);
            }
        }
        // cout << u << endl;
        cvis[u] = 1; 
        type[u] = d;
        for(int n : adj[u]){
            if(!cvis[n]){
                initsz(n); 
                int ncent = init(n, csz[n], u, d+1);
                cpar[ncent] = u;
                // cout << u << " " << ncent << " " << cpar[ncent].s << endl;
            }
        }
        cvis[u] = 0;
        return u;
    }
 
    centroidDecomp(){
        initsz(1);
        int root = init(1, csz[1]);
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, u, v; cin >> N;
    for(int i = 0; i<N-1; i++){
        cin >> u >> v; adj[u].pb(v); adj[v].pb(u);
    }
    centroidDecomp cd;
    for(int i = 1; i<=N; i++){
        cout << type[i] << " ";
    }
    return 0;
}
