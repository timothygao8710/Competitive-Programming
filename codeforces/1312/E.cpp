//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

const int maxn = 505;
int dp[maxn][maxn];
int dpp[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    fill(begin(dpp), end(dpp), N*2);
    vector<int> nums(N);
    for(int i =0; i<N; i++){
        cin >> nums[i]; dp[i][i] = nums[i];
    }

    for(int i = N-1; i>=0; i--){
        for(int j = i+1; j<N; j++){
            for(int k = i+1; k<=j; k++){
                if(dp[i][k-1] && dp[k][j] && dp[i][k-1] == dp[k][j]){
                    dp[i][j] = dp[k][j]+1;
                }
            }
        }
    }
    //cout << dp[2][3] << endl;
    dpp[N] = 0;
    for(int i = N-1; i>=0; i--){
        for(int j = i; j<N; j++){
            if(dp[i][j]){
                //cout << i << " " << j << endl;
                dpp[i] = min(dpp[i], dpp[j+1]+1);
            }
        }
        //cout << dpp[i] << endl;
    }
    cout << dpp[0];
    return 0;
}
