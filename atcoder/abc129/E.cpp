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
    string str; cin >> str; int N = str.length();
    vector<vector<ll>> dp(N+1);
    vector<int> nums(N+1);
    for(int i= 1; i<=N; i++) {
        nums[i] = str[i-1] - '0';
        dp[i].resize(2);
    }   
    dp[0].resize(2);
    //0 - =
    //1 - <
    dp[0][0] = 1;
    for(int i = 1; i<=N; i++){
        if(nums[i]){
            dp[i][0] = 2* dp[i-1][0];
            dp[i][1] = dp[i-1][0] + 3*dp[i-1][1];
        }else{
            dp[i][0] = dp[i-1][0];
            dp[i][1] = 3*dp[i-1][1];
        }
        dp[i][0] %= mod;
        dp[i][1] %= mod;
        // cout << dp[i][0] << " " << dp[i][1] << endl;
    }
    cout << (dp[N][0] + dp[N][1])%mod;
    return 0;
}
