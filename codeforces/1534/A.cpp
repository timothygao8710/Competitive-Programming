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
    int T; cin >> T;
    for(int t = 0; t<T; t++){
        int N, M; cin >> N >> M;
        int grid[N][M], test[N][M];
        for(int i = 0; i<N; i++){
            string line; cin >> line;
            for(int j = 0; j<M; j++){
                grid[i][j] = (line[j] == 'R');
                if(!grid[i][j]){
                    grid[i][j] = -(line[j] == '.');
                }
            }
        }
        bool ok = false;
        for(int k = 0; k<2; k++){
            if(grid[0][0] != -1 && k != grid[0][0]) continue;
            test[0][0] = k; bool bad = false;
            for(int i = 0; i<N; i++){
                for(int j = 0; j<M; j++){
                    if(i == 0 && j == 0){
                        continue;
                    }
                    test[i][j] = grid[i][j];
                    if(i-1 >= 0){
                        if(test[i][j] == test[i-1][j]){
                            bad = true;
                        } 
                        test[i][j] = test[i-1][j]^1;
                    }
                    if(j-1 >= 0){
                        if(test[i][j-1] == test[i][j]) {
                            bad = true;
                        }
                        test[i][j] = test[i][j-1]^1;
                    }
                    // cout << test[i][j] << " ";
                }
                // cout << endl;
            }
            if(bad) continue;
            cout << "YES\n";
            for(int i = 0; i<N; i++){
                for(int j = 0; j<M; j++){
                    cout << (test[i][j] ? "R" : "W");
                }
                cout << "\n";
            }
            ok = true;
            break;
        }   
        if(!ok) cout << "NO\n";
    }
    return 0;
}
