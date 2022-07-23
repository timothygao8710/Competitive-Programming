//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

//https://codeforces.com/blog/entry/81661?#comment-686024

const int maxn = 2e5 + 8;
vector<int> adj[maxn];
unordered_map<int, int> pars[maxn];
vector<int> comps[maxn]; //each centroid's component
int csz[maxn], blocked[maxn]; //csz[u] will change overtime
 
struct centroidDecomp{
    //N log(N) calculations for each component
    void calc(int u, int cent, int p = 0, int val = 0){
        pars[u][cent] = val; 
        comps[cent].pb(u);
        for(int n : adj[u]){
            if(!blocked[n] && n != p) {
                calc(n, cent, u, val+1);
            }
        }
    }
 
    int initsz(int u, int p = 0){ //finds the sz of current group/component
        csz[u] = 1;
        for(int n : adj[u]){
            if(!blocked[n] && n != p) csz[u] += initsz(n, u);
        }
        return csz[u];
    }
 
    int init(int u, int compsz, int p = 0){
        for(int n : adj[u]){
            if(n != p && !blocked[n] && csz[n] > compsz/2){
                return init(n, compsz, u);
            }
        }
        // cout << u << endl;
        blocked[u] = 1, calc(u, u);
        for(int n : adj[u]){
            if(!blocked[n]){
                initsz(n); 
                init(n, csz[n], u);
            }
        }
        blocked[u] = 0;
        return u;
    }
    
    //must be 1-indexed
    centroidDecomp(){
        initsz(1);
        init(1, csz[1]);
    }
};