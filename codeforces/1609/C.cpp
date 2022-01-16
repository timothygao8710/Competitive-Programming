// Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

ll chooseTwo(ll N){
    // return N * (N-1)/2;
    return N;
}

int main(){

    int maxn =1e6 + 9;
    vector<int> comp(maxn);
    for(int i = 2; i<maxn; i++){
        if(comp[i]) continue;
        for(int j = i+i; j<maxn; j+=i){
            comp[j] = 1;
        }
    }



    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N, E; cin >> N >> E;
        vector<vector<int>> mods(E);
        for(int i = 0; i<N; i++){
            int a; cin >> a; mods[i%E].pb(a);
        }
        ll ret = 0;
        for(vector<int> v : mods){
            vector<int> temp; temp.pb(v.size());
            for(int j = v.size()-1; j>=0; j--){
                // cout << v[j] << " ";
                if(comp[v[j]]){
                    // cout << "DUDSFS" << v[j] << endl;
                    temp.clear(); temp.pb(j); continue;
                }
                if(v[j] == 1){
                    if(temp.size() >= 2){
                        ret += temp[(int)temp.size()-2]-temp[(int)temp.size()-1];
                    }
                }else{
                    ret += temp[(int)temp.size()-1] - j - 1; 
                    temp.pb(j);
                }
            }
        }
        cout << ret << '\n';
    }    
    /*
    1
    7 3
10 2 1 3 1 19 3
    */
    return 0;
}
