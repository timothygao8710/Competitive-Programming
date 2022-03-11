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
        vector<array<int, 4>> ret; int ok = 1;
        int N, M; cin >> N >> M;
        for(int i = 0; i<N; i++){
            string str; cin >> str;
            if(i != 0){
                if(str[0] == '1'){
                    ret.pb({i-1, 0, i, 0});
                }
            }else{
                if(str[0] != '0') {
                    ok = 0;
                }
            }
            for(int j = 1; j<M; j++){
                if(str[j] == '1'){
                    // cout << i << " " << j << endl;
                    ret.pb({i, j-1, i, j});
                }
                
            }
        }
        if(!ok){
            cout << -1 << '\n'; continue;
        }
        reverse(ret.begin(), ret.end());
        cout << ret.size() << '\n';
        for(auto i : ret){
            cout << (i[0] + 1) << " " << (i[1] + 1) << " " << (i[2] + 1) << " " << (i[3] + 1) << '\n';
        }
    }    
    return 0;
}
