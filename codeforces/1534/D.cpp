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
    int T=1;
    while(T--){
        int N, u; cin >> N;
        vector<int> par[2];
        vector<pii> ret;
        cout << "? " << 1 << endl;
        for(int i = 1; i<=N; i++){
            cin >> u;
            par[u%2].pb(i);
            if(u == 1){
                ret.pb(pii(i, 1));
            }
        }
        if(par[1].size() < par[0].size()){
            swap(par[0], par[1]); ret.resize(0);
        }
        for(int i : par[0]){
            if(i == 1) continue;
            cout << "? " << i << endl;
            for(int j = 1; j<=N; j++){
                cin >> u;
                if(u == 1){
                    ret.pb(pii(i, j));
                }
            }
        }
        assert(ret.size() == N-1);
        cout << "!\n";
        for(pii i : ret){
            cout << i.f << " " << i.s << endl;
        }
    }    
    return 0;
}
