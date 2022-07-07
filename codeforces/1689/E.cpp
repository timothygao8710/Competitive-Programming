//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

struct DSU{
    int tot;
    vector<int> par, sz;
    DSU(int n){
        par.reserve(n); sz.reserve(n);
        for(int i = 0; i<n; i++) {
            par.pb(i); sz.pb(1);
        }
        tot = n;
    }

    int root(int u){
        return par[u] == u ? u : par[u] = root(par[u]);
    }

    void unite(int u, int v){
        int ru = root(u); int rv = root(v);
        if(ru == rv) return;
        if(sz[rv] > sz[ru]) swap(ru, rv);
        sz[ru] += sz[rv];
        par[rv] = ru;
        tot--;
    }
};

int lbit(int a){
    return a & -a;
}

int getComp(vector<int>& nums, int N){
    DSU dsu(N);
    vector<int> last(30, -1);

    for(int i=0; i<N; i++){
        for(int j = 0; j<30; j++){
            if((nums[i]>>j)&1){
                if(last[j] != -1){
                    dsu.unite(last[j], i);
                }
                last[j] = i;
            }
        }
    }

    return dsu.tot;
}

void printRes(int moves, vector<int>& nums){
    cout << moves << '\n';
    for(int i : nums){
        cout << i << " ";
    }
}

//each component is some subset of bits, at most 30 components
void solve(){
    int N; cin >> N;
    vector<int> nums(N);
    int zeroes = 0;
    for(int i = 0; i<N; i++){
        cin >> nums[i];
        if(nums[i] == 0){
            zeroes++; nums[i] = 1;
        }
    }
    if(getComp(nums, N) == 1){
        printRes(0 + zeroes, nums);
        return;
    }

    //is the answer 1? Not nessesarily decrease num with greatest least bit
    for(int i = 0; i<N; i++){
        nums[i]++;
        if(getComp(nums, N) == 1){
            printRes(1 + zeroes, nums);
            return;
        }
        nums[i]--;
        nums[i]--;
        if(getComp(nums, N) == 1){
            printRes(1 + zeroes, nums);
            return;
        }
        nums[i]++;
    }
    
    //if we subtract from glb, the only component that can be disconnected is with other nums with same glb
    //in that case we just add 1 to one of the other nums to reconnect
    int glb = -1;
    vector<int> idxs;
    for(int i = 0; i<N; i++){
        int cur = lbit(nums[i]);
        if(cur > glb){
            glb = cur;
            idxs.clear();
        }
        if(cur == glb){
            idxs.pb(i);
        }
    }
    assert((int)(idxs.size()) > 1);
    nums[idxs[1]]++;
    nums[idxs[0]]--;
    printRes(2+zeroes, nums);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        solve();
        cout << '\n';
    }
    return 0;
}
