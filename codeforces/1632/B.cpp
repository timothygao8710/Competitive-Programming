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
        int N; cin >> N;
        int gbit = 0;
        for(int i=0; i<N; i++){
            for(int j = 30; j>=0; j--){
                if((i>>j)&1) {
                    gbit = max(gbit, j);
                    break;
                }
            }
        }
        vector<int> ret;
        for(int i = N-1; i>=0; i--){
            if(((1<<gbit)&i)) ret.pb(i);
        }
        ret.pb(0);
        for(int i = N-1; i>=1; i--){
            if(((1<<gbit)&i) == 0) ret.pb(i);
        }
        for(int i : ret) cout << i << " ";
        cout << '\n';
    }    
    return 0;
}
