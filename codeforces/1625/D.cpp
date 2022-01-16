//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

struct trie{
    trie* nxt[2] = {0,0};

    void insert(int val, int idx = 31){
        if(idx < 0) return;
        int c = (val >> idx)&1;
        if(nxt[c] == 0) nxt[c] = new trie();
        nxt[c] -> insert(val, idx-1);
    }

    int query(int x, int idx = 31){
        if(idx < 0) return 0;
        int c = (x >> idx)&1;
        if(nxt[c^1] != 0){
            return (1<<idx) + nxt[c^1] -> query(x, idx-1);
        }
        assert(nxt[c] != 0);
        return nxt[c] -> query(x, idx-1);
    }
};

int getGreatestBit(int x){
    for(int i = 30; i>=0; i--){
        if((x>>i)&1){
            return i; 
        }
    }
    assert(x == 0);
    return -1;
}
int N, K, g;
vector<int> ret;
void solve(vector<pii>& rems, int K){
    int mx = rems[0].f, idx = rems[0].s;
    trie tree;
    int n = rems.size();
    tree.insert(rems[0].f); 
    
    for(int i = 1; i<n; i++){
        int x = tree.query(rems[i].f);
        if(x >= K){
            for(int j = 0; j<i; j++){
                if(x == (rems[j].f ^ rems[i].f)){
                    ret.pb(rems[j].s); ret.pb(rems[i].s);
                    break;
                }
            }
            mx = -1;
            break;
        }
        tree.insert(rems[i].f);
        if(rems[i].f > mx){
            mx = rems[i].f, idx = rems[i].s;
        }
    }
    if(mx != -1){
        ret.pb(idx);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> K; g = getGreatestBit(K);
    map<int, vector<pii>> vals;
    if(K == 0) cout << N << endl;
    for(int i = 0; i<N; i++){
        int a; cin >> a;
        if(K == 0) cout << i+1 << " ";
        vals[a >> (g+1)].pb(pii(a, i));
    }
    if(K == 0) return 0;
    for(auto i : vals){
        solve(i.s, K);
    }
    if((int)(ret.size()) < 2){
        cout << -1 << endl; return 0;
    }
    // sort(ret.begin(), ret.end());
    cout << (int)(ret.size()) << endl;
    for(int i : ret) {
        cout << i+1 << " ";
    }
    return 0;
} //16, 2, 14
