//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

const int maxs = 1<<16;
ll cost[maxs], dp[maxs];
ll nums[16][16];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N; int sub = 1<<N;
    for(int i = 0; i<N; i++) {
        for(int j = 0; j<N; j++) {
            cin >> nums[i][j];
        }
    }
    // cout << cost[15] << endl;
    for(int i = 1; i<sub; i++){
        int lsb = i&-i, mask = i^lsb, shift = log2(lsb);
        cost[i] = cost[mask];
        for(int j = 0; (1<<j) <= mask; j++){
            if((mask>>j)%2){
                cost[i] += nums[shift][j]; 
                
            }
        }
        //cout << i << " " << cost[i] << " " << endl;;
    }
    for(int i = 1; i<sub; i++){
        dp[i] = cost[i];
        for(int s = i; s>0; s = ((s-1)&i)){ //this is last state
            dp[i] = max(dp[i], dp[s] + cost[i^s]);
        }
    }
    cout << dp[(1<<N)-1];
    return 0;
}
