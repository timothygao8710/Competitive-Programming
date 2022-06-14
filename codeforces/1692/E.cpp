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
        int N, S; cin >> N >> S;
        map<int, int> mp;
        mp[0] = -1;
        int run = 0, ret = (int)1e9;
        for(int i = 0; i<N; i++){
            int a; cin >> a;
            run += a;
            if(!mp.count(run)) mp[run] = i;
            if(mp.count(run - S)){
                ret = min(ret, N - i - 1 + mp[run-S] + 1);
            }
        }
        if(ret == (int)1e9){
            cout << -1 << '\n';
        }else{
            cout << ret << '\n';
        }
    }    
    return 0;
}
