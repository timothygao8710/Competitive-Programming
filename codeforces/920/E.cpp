//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, M; cin >> N >> M;
    vector<int> ret;
    set<int> left;
    set<pii> edges;
    for(int i = 0; i<M; i++){
        int u, v; cin >> u >> v;
        edges.insert(pii(u, v)); edges.insert(pii(v, u));
    }
    for(int i = 1; i<=N; i++) left.insert(i);
    for(int i = 1; i<=N; i++){
        if(!left.count(i)) continue;
        int sz = 1;
        stack<int> cur; cur.push(i);
        left.erase(i);
        while(!cur.empty()){
            vector<int> temp;
            int c = cur.top(); cur.pop();
            for(int j : left){
                if(edges.count(pii(c, j))) continue;
                temp.pb(j); sz++;
            }
            for(int j : temp) left.erase(j), cur.push(j);
        }
        ret.pb(sz);
    }
    sort(ret.begin(), ret.end());
    cout << ret.size() << endl;
    for(int i : ret) cout << i << " ";
    return 0;
}
