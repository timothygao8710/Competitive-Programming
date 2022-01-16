//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second
const int INF = 1e9 +7;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T, N, K; cin >> T;
    while(T--){
        cin >> N >> K;
        int nums[N];
        for(int i = 0; i<N; i++){
            cin >> nums[i];
        }
        int dp[N+1][N];
        for(int i = 0; i<=N; i++){
            for(int j = 0; j<N; j++){
                dp[i][j] = 0;
            }
        }
        // fill(dp[0], dp[0] + N, 0);
        for(int i = 1; i<=N; i++){
            for(int j = 0; j<=i; j++){
                dp[i][j] = dp[i-1][j] + (i-j == nums[i-1]);
                // cout << i << " " << nums[i-1]  << " " << j << endl;
                // cout << i-j <<  " " << nums[i-1]<< endl;
                if(j != 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
                // cout << dp[i][j] << " ";
            }
            // cout  << endl;
        }
        int best = INF;
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                if(best == INF && dp[j+1][i] >= K){
                    best = i;
                }
            }
        }
        // cout << T << endl;
        cout << (best == INF ? -1 : best) << '\n';
    }    
    return 0;
}
/*
1
7 6
1 1 2 3 4 5 6
*/