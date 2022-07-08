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
        vector<vector<int>> grid(2, vector<int>(2));
        int one = 0, zero = 0;
        for(int i = 0; i<2; i++){
            for(int j = 0; j<2; j++){
                cin >> grid[i][j];
                one = one || grid[i][j];
                zero = zero || !grid[i][j];
            }
        }
        if(!one){
            cout << 0 << '\n'; continue;
        }
        if(zero){
            cout << 1 << '\n'; continue;
        }
        cout << 2 << endl;
    }    
    return 0;
}
