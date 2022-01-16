//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

const int maxn = 5e5 + 32;
const int mod = 998244353;
ll dp[maxn][2]; //val : has next ?
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        for(int i = 0; i<N+69; i++) dp[i][0] = dp[i][1] = 0;
        dp[0][0] = 1;
        for(int i = 0; i<N; i++){
            int a; cin >> a;
            if(a-1 >= 0){
                dp[a-1][1] *= 2;
                dp[a-1][1] += dp[a-1][0]; dp[a-1][1] %= mod;
            }
            dp[a+1][0] *= 2; 
            dp[a+1][1] *= 2; dp[a+1][1] %= mod;
            dp[a+1][0] += dp[a][0]; dp[a+1][0] %= mod;
        }
        ll ret = 0;
        for(int i = 0; i<=N+1; i++) ret += dp[i][0] + dp[i][1], ret %= mod;
        cout << (ret-1+mod)%mod << '\n';
    }

    return 0;
}