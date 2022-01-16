//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

// int nums[6000];

int dp[5005][5005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, K; 
    cin >> N >> K; int nums[N+1];
    map<int, int> last;
    for(int i = 1; i<=N; i++) {
        cin >> nums[i];
    }
    sort(nums+1, nums+N+1);
    for(int i = 1; i<=N; i++){
        if(last[nums[i]] == 0) last[nums[i]] = i;
        int l = last.lower_bound(nums[i]-5)->s;
        int test = last.upper_bound(nums[i] - 5) -> s;
        // if(l == i){
        //     for(int j = 1; j<=K; j++){
        //         dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]+1);
        //     }
        // }else{
            for(int j = 1; j<=K; j++){
                dp[i][j] = max(dp[i-1][j], dp[l-1][j-1] + i - l + 1);
            }
        // }
    }
    cout << dp[N][K] << endl;
    return 0;
}
/*
3 1
1 5 10
*/