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
    while(T--){
        ll N, K; cin >> N >> K;
        K--;
        vector<int> go(N), perm(N); bool ok = 1;
        for(int i = 0; i<N; i++){
            perm[i] = i+1;
        }
        for(int i = 0; i<62; i++){
            if((K>>i)%2){
                if(N-2-i < 0) {
                    ok = 0; break;
                }
                go[N-2-i]++;
            }
        }
        if(!ok) {
            cout << -1 << '\n'; continue;
        }

        for(int i = N-2; i>=0; i--){
            if(go[i]) go[i] += go[i+1];
        }
        for(int i = 0; i<N; i++){
            reverse(perm.begin()+i, perm.begin()+i+go[i]+1);
            i = i+go[i];
        }

        for(int i : perm){
            cout << i << " ";
        }
        cout << '\n';
    }
    
    return 0;
}
//11100100
//9 229