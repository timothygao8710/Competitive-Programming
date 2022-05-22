//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

const int mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
    int N, M; cin >> N >> M;
    //If we predetermine a set of areas to be >0
    //then its configuration is unique
    //via flooding-in type argument
    ll ret = 1, ok = 0;
    for(int i = 0; i<N; i++){
        string str; cin >> str;
        for(int j = 0; j<M; j++){
            if(str[j] == '#'){
                ret = (ret * 2) % mod;
            }else{
                ok++;
            }
        }
    }    
    if(!ok) ret = (ret - 1 + mod) % mod;
    cout << ret << '\n';
    }
    return 0;
}
