//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second
/*
observations:
- only greatest bit matters (equal or not?)
- if bit i has N, then at least N-1 non-bit-i
- max(a,b) >= (a+b+1)/2
*/
const int maxn = 2e5+6;
vector<int> bipart[2];
vector<int> adj[maxn];

int getF(int x){
    for(int i = 30; i>=0; i--){
        if((x>>i)&1) return i;
    }
    assert(false);
    return -1;
}

void dfs(int u, int p = -1, int h = 69){
    bipart[h%2].pb(u);
    for(int n : adj[u]){
        if(n != p) dfs(n, u, h+1);
    }
}
bool cmp(vector<int>& a, vector<int>& b){
    return a.size() > b.size();
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vector<vector<int>> bits(32); vector<int> ret(N);
        for(int i = 0; i<N; i++){
            adj[i].clear(); bits[getF(i+1)].pb(i+1);
        }
        for(int i = 0; i<N-1; i++){
            int u, v; cin >> u >> v; u--, v--;
            adj[u].pb(v); adj[v].pb(u);
        }
        dfs(0);
        sort(bits.begin(), bits.end(), cmp);
        for(int i = 0; i<31; i++){
            if(bipart[0].size() < bipart[1].size()) swap(bipart[0], bipart[1]);
            for(int j : bits[i]){
                int cur = bipart[0].back(); bipart[0].pop_back();
                ret[cur] = j;
            }
        }
        assert(bipart[0].empty() && bipart[1].empty());
        for(int i : ret) cout << i << " ";
        cout << '\n';
    }
    return 0;
}
