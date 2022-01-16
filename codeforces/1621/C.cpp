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
    int T; cin >> T;
    while(T--){
        set<int> vis;
        int N, a, turns=1; cin >> N;
        vector<int> ret(N);
        cout << "? " << 1 << endl;
        cin >> a; assert(a == 1);
        
        for(int i = 1; i<=N; i++){
            if(vis.count(i)) continue;
            
            vector<int> cycle;
            int cur = i, nxt = -1;       
                 
            while(vis.size() < N){
                // cout << "OK" << endl;
                cout << "? " << i << endl;
                cin >> nxt;
                swap(cur, nxt);
                if(!cycle.empty() && cycle[0] == cur) break;
                // cout << "brih" << endl;
                vis.insert(cur);
                cycle.pb(cur);
            }
            
            int c = cycle.size();
            // cout << "size" << c << endl;
            // for(int j = (turns%(c)), k = 0; k < (c); k++, j = (j+1)%(c)){
            //     ret[cur] = cycle[j];
            //     cur = cycle[j];
            // }
            int last = c-1;
            for(int j = 0; j<c; j++){
                ret[cycle[last]-1] = cycle[j];
                last = (last+1)%c;
            }
            turns += c;
        }
        cout << "! ";
        for(int i : ret) cout << i << " ";
        cout << endl;
    }    
    return 0;
}
