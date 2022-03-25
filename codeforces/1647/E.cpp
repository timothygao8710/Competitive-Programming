//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

//Cheeky observation: number of moves so far can be determined easily, through looking at inDeg=0 nodes
//Now, we need to find for each element the number of previous that have moved K

//We can use the property that a functional graph is series of loops of disjoint trees, but the dfs will be long and messy
//each node has 1 up destination --> binary lifting

const int mx = 31;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int N; cin >> N;
    vector<vector<int>> up(mx, vector<int>(N)), at(N, vector<int>());
    vector<int> inDeg(N), end(N);
    int free = N, K = 0;

    for(int i = 0; i<N; i++){
        int a; cin >> a; --a;
        up[0][i] = a;
        if(inDeg[a] == 0) free--;
        inDeg[a]++;
    }

    for(int i = 1; i<mx; i++){
        for(int j = 0; j<N; j++){
            up[i][j] = up[i-1][up[i-1][j]];
        }
    }
    map<int, int> all;
    for(int i = 0; i<N; i++){
        cin >> end[i]; all[end[i]] = i;
        if(!inDeg[i]) K = end[i];
    }
    K -= N; K = max(0, K); //If noDeg has mx, ok; other wise, assume it does
    assert(K%free == 0); //must have at least one noDeg <- hidden in a sneaky condition
    K /= free;
    // cout << K << endl;
    vector<int> ret(N);
    for(int i = 0; i<N; i++){
        int cur = i;
        for(int j = 0; j<mx; j++){
            if((K>>j)&1) {
                cur = up[j][cur];
            }
        }
        at[cur].pb(i);
    }
    for(int i =0; i<N; i++) {
        // cout << i << " " << at[i].size() << endl;
        sort(at[i].begin(), at[i].end());
    }
    set<int> avaliable;
    for(int i = 1; i<=N; i++){
        if(all.count(i)){
            int idx = all[i];
            assert(!at[idx].empty());
            ret[at[idx][0]] = i;
            for(int j = 1; j<(int)(at[idx].size()); j++){
                avaliable.insert(at[idx][j]);   
            }
        }else{
            int mn = *avaliable.begin();
            avaliable.erase(mn);
            ret[mn] = i;
        }
    }
    for(int i : ret) cout << i << " ";
    return 0;
}
