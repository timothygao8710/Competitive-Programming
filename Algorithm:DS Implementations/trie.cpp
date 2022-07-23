//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

const int maxn = 2e5;

//LINEAR TRIE:
int trie[33*maxn][2], tIdx = 0;
 
void insert(int x) {
    int node = 0;
    for (int i=29; i>=0; i--) {
        int c = x&(1<<i) ? 1 : 0;
        if (trie[node][c] == -1) trie[node][c] = ++tIdx;
        node = trie[node][c];
    }
}
 
//get max xor query
int query(int x) {
    int res = 0, node = 0;
    for (int i=29; i>=0; i--) {
        int c = x&(1<<i) ? 0 : 1;
        if (trie[node][c] != -1) {
            res ^= 1<<i;
            node = trie[node][c];
        } else {
            node = trie[node][1^c];
        }
    }
    return res;
}

//CLASS BASED TRIE
struct trie{
    trie* nxt[2] = {0,0};

    void insert(int val, int idx = 29){
        if(idx < 0) return;
        int c = (val >> idx)&1;
        if(nxt[c] == 0) nxt[c] = new trie();
        nxt[c] -> insert(val, idx-1);
    }

    //get max xor query
    int query(int x, int idx = 29){
        if (idx < 0) return 0;
        int cur = (x>>idx)&1;
        if(nxt[cur^1] != 0){ //greedily maximize
            return nxt[cur^1] -> query(x, --idx);
        }
        return nxt[cur] -> query(x, --idx);
    }
};