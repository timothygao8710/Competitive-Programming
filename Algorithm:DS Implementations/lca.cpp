//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

const int maxn = 2e5 + 7;
int lift[19][maxn]; //1-indexed, 0 if no ancestor
int height[maxn];

int up(int u){
    if(height[u] != -1) return height[u];
    height[u] = 0;
    for(int i = 18; i>=0; i--){
        if(lift[i][u]){
            height[u] = up(lift[i][u]) + (1<<i);
        }
    }
    return height[u];
}

int jump(int u, int k){ //view k in binary
    for(int i = 0; i<19; i++){
        if((k >> i) & 1){
            u = lift[i][u];
        }
    }
    return u;
}

int lca(int u, int v){
    if(height[v] > height[u]) swap(u, v);
    u = jump(u, height[u] - height[v]);
    assert(height[u] == height[v]);
    if(u == v) {
        return u;
    }
    for(int i = 18; i>=0; i--){ //jump pows strictly decrease
        if(lift[i][u] != lift[i][v]){
            u = lift[i][u]; v = lift[i][v];
        }
    }
    return lift[0][u];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q, a, b; cin >> n >> q; memset(lift[0], 0, sizeof(lift));

    memset(lift[0], 0, sizeof(lift[0]));
    for(int i = 2; i<=n; i++){
        cin >> lift[0][i];
    }
    //init lift
    for(int i = 1; i<19; i++){
        for(int j = 0; j<maxn; j++){
            lift[i][j] = lift[i-1][lift[i-1][j]];
        }
    }
    memset(height, -1, sizeof(height));
    for(int i = 1; i<=n; i++){
            up(i);
        // cout << height[i] << " ";
    }
    for(int i = 0; i<q; i++){
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
    return 0;
}
