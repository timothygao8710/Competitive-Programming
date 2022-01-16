//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T, N, M, c; cin >> T;
    while(T--){
        vector<vector<int>> table;
        cin >> N >> M;
        for(int i = 0; i<N; i++){
            vector<int> cur;
            for(int j = 0; j<M; j++){
                cin >> c;
                cur.pb(c);
            }
            table.pb(cur);
        }
        vector<int> order;
        // cout << endl;
        for(int i = 0; i<N; i++){
            cin >> c; order.pb(c);
            // cout << order[i] << " ";
        }
        for(int i = 1; i<M; i++) for(int j = 0; j<N; j++) cin >> c;
        int idx = 0;
        for(int i =0; i<N; i++){
            for(int k = 0; k<N; k++){
            for(int j =0; j<M; j++){
                if(order[i] == table[k][j]){
                    idx = j;
                }
            }
            }
        }
        // cout << idx;
        for(int i = 0; i<N; i++){
            for(int j =0; j<N; j++){
                if(order[i] != table[j][idx]) continue;
                for(int k = 0; k<M; k++){
                    cout << table[j][k] << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}
