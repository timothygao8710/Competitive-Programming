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
    
    vector<array<int, 3>> precomp;
    for(int i = 0; i<=9; i++){
        for(int j = 0; j<=9; j++){
            for(int k = 0; k<=9; k++){
                if((i + j + k)%10 == 3){
                    precomp.pb({i, j, k});
                }
            }
        }
    }
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vector<int> occ(10);
        for(int i = 0; i<N; i++){
            int a; cin >> a; occ[a%10]++;
        }
        int ret = 0;
        for(auto i : precomp){
            int ok = 1;
            for(int j : i){
                occ[j]--;
                if(occ[j] < 0) ok = 0;
            }
            ret = ret || ok;
            for(int j : i){
                occ[j]++;
            }
        }
        cout << (ret ? "YES" : "NO") << '\n';
    }
    return 0;
}
