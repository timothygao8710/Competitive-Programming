//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

vector<int> sz;
int dfs(int u, int p, vector<vector<int>>& adj){
    int ret = ((int)adj[u].size()) - (p != -1);
    if(ret) sz.pb(ret);
    // cout << u << " " << ret << endl;
    for(int n : adj[u]){
        if(n == p) continue;
        // cout << n << " " << u << endl;
        ret += dfs(n, u, adj);
    }
    return ret;
}

int get(vector<int>& nums, int K){
    int ret = 0;
    for(int i : nums){
        ret += max(0, i-K);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        sz.clear();
        int N; cin >> N; sz.pb(1);
        vector<vector<int>> adj(N, vector<int>());
        for(int i = 1; i<N; i++){
            int p; cin >> p; --p;
            adj[p].pb(i); adj[i].pb(p);
        }
        dfs(0, -1, adj);
        //I misread the problem...
        sort(sz.begin(), sz.end());
        reverse(sz.begin(), sz.end());
        int ret = 0;
        vector<int> all;
        for(int i = 0; i<(int)sz.size(); i++){
            // cout << sz[i] << " ";
            vector<int> step;
            for(int j : all){
                if(j-1 > 0) step.pb(j-1);
            }
            swap(step, all);
            sz[i]--; ret++; 
            if(sz[i]) all.pb(sz[i]);
        }
        if(all.empty()){
            cout << ret << '\n'; continue;
        }
        int l = 0;
        int r = N;
        while(l < r){
            int mid = (l+r)/2;
            if(get(all, mid) <= mid){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        cout << (ret + r) << '\n';
    }    
    return 0;
}
