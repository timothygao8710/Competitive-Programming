//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

const int mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

        int N, K; cin >> N >> K;
        vector<int> dp(2e5);
        dp[0] = 1;
        for(int i = 1; i<2e5; i++){
            dp[i] = dp[i-1];
            if(i-K >= 0) dp[i] += dp[i-K];
            if(dp[i] > mod) dp[i] -= mod;
        }
        for(int i = 1; i<2e5; i++){
            dp[i] += dp[i-1]; if(dp[i] > mod) dp[i] -= mod;
        }
        while(N--){
            int l, r; cin >> l >> r;
            cout << (dp[r] - dp[l-1] + mod)%mod << '\n';
        }
    
    return 0;
}
