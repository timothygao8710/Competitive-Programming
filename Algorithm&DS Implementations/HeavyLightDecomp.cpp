//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

template <typename T>
struct segtree
{
    T none; //comb(a, none) = a

    T val;
    int gL, gR, mid;
    segtree<T> *left;
    segtree<T> *right;

    T comb(T& l, T& r)
    {
        return min(l, r); //modify
    }

    segtree(int l, int r, vector<T>& arr, T non)
    { //modify arr type
        none = non;
        gL = l; gR = r; mid = (gL+gR)/2;
        if (l == r)
        {
            val = arr[l];
        }
        else
        {
            
            left = new segtree<T>(l, mid, arr, non); right = new segtree<T>(mid + 1, r, arr, non);
            val = comb(
                left->val, right->val);
        }
    }

    T query(int l, int r)
    {

        if (gL > r || gR < l)
        {
            return none;
        }

        if (gL == l && gR == r)
        {
            return val;
        }
        T a = left->query(l, min(r, mid)); T b = right->query(max(l, mid + 1), r);
        return comb(a, b); //might be wrong
    }

    void update(int idx, T set)
    {
        if (gL == gR)
        {
            val = set;
        }
        else
        {
            if (idx <= (gL + gR) / 2)
            {
                left->update(idx, set);
            }
            else
            {
                right->update(idx, set);
            }
            val = comb(left->val, right->val);
        }
   }
};

const int INF = 1e9+7;
const int maxn = 2e5;
vector<pair<int, int>> adj[maxn];

//assumes adj already given
struct chain{
    //par is node, not color of node
    int par = -1, head, mn = INF;
    vector<int> vals; //lowest to highest
    unordered_map<int, int> mp;
    segtree<int>* sgt;

    void add(int v){
        mp[v] = vals.size();
        vals.pb(v); mn = min(mn, v);
        head = v;
    }
};

struct HLD
{
    vector<chain> chains;
    int color[maxn], sz[maxn], depth[maxn];

    void dfs(int u, int d, int p = -1){
        depth[u] = d;
        sz[u]=1;
        if(p!=-1 && adj[u].size() == 1){
            color[u] = chains.size();
            chains.pb(chain()); 
            // chains[color[u]].add(u);
            return;
        }
        
        pair<int, int> best;
        for(auto i : adj[u]){
            if(i.f == p) continue;
            dfs(i.f, d+1, u);
            sz[u] += sz[i.f]; 
            if(sz[i.f] > best.f){
                best.f = sz[i.f];
                best.s = i.s;
                color[u] = color[i.f];
            }
        }
        chains[color[u]].add(best.s);
        for(auto i : adj[u]){
            if(i.f == p) continue;
            if(color[i.f] != color[u]){
                chains[color[i.f]].par = u;
            }
        }
    }

    int query(int a, int b){
        int ret = INF;
        while(color[a] != color[b]){
            chain* ca = &chains[color[a]];
            chain* cb = &chains[color[b]];
            if(depth[ca -> head] < depth[cb -> head]){
                ret = min(ret, ca -> mn);
                a = ca -> par;
            }
        }
        //return depth[a] < depth[b] ? a : b; for lca
    }

    HLD(int root){
        dfs(root, 0);
        for(chain c : chains){
            c.sgt = new segtree(0, c.vals.size()-1, c.vals, INF);
        }
    }
};

//TODO: rewrite with 2dfs, so we can get all chains as contiguous intervals on a single seg tree