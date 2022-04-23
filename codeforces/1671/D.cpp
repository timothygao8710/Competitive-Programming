//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

const int maxn = 2e5 + 100;
ll dp[maxn][2][2];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    while(T--){
        int N, X; cin >> N >> X;
        // for(int i = 0; i<maxn; i++) for(int j = 0; j<2; j++) for(int k = 0; k<2; k++) dp[i][j][k] = 0;
        vector<int> nums(N); for(int i =0; i<N; i++) cin >> nums[i];
        dp[0][1][0] = abs(nums[0] - 1);
        dp[0][0][1] = abs(nums[0] - X);
        dp[0][0][0] = 0;
        dp[0][1][1] = min(abs(nums[0] - X), abs(nums[0] - 1)) + X - 1;
        for(int i = 1; i<N; i++){
            for(int j = 0; j<2; j++){
                for(int k = 0; k<2; k++){
                    dp[i][j][k] = dp[i-1][j][k] + abs(nums[i] - nums[i-1]);
                    if(j){
                        dp[i][j][k] = min(dp[i][j][k], dp[i-1][0][k] + abs(nums[i] - 1) + abs(nums[i-1] - 1));
                    }   
                    if(k){
                        dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][0] + abs(nums[i] - X) + abs(nums[i-1] - X));
                    }
                    if(j && k){
                        dp[i][j][k] = min(dp[i][j][k],
                            dp[i-1][0][0] + X - 1 + min(abs(nums[i-1] - 1) + abs(nums[i] - X) , abs(nums[i-1] - X) + abs(nums[i] - 1))
                        );
                    }
                }
            }
        }
        ll ret = dp[N-1][1][1];
        ret = min(ret, dp[N-1][0][1] + abs(nums[N-1] - 1));
        ret = min(ret, dp[N-1][1][0] + abs(nums[N-1] - X));
        ret = min(ret, dp[N-1][0][0] + min(abs(nums[N-1] - X), abs(nums[N-1] - 1)) + X - 1);
        cout << ret << '\n';
    }

    return 0;
}
