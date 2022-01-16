//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

const int bket = 300;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, M; cin >> N >> M;
    vector<int> nums(N);
    vector<pii> dp(N);
    for(int i = 0; i<N; i++){
        cin >> nums[i];
    }
    for(int i = N-1; i>=0; i--){
        if((i + nums[i])/bket != i/bket || i + nums[i] >= N){
            dp[i] = pii(i + nums[i], 1);
            
        }else{
            dp[i] = pii(dp[i+nums[i]].f, dp[i+ nums[i]].s + 1);
        }
    }
    while(M--){
        int type, idx, B;
        cin >> type >> idx; idx--;
        if(type == 1){
            int ret = 0;
            while(dp[idx].f < N){
                ret += dp[idx].s;
                idx = dp[idx].f;
            }
            ret += dp[idx].s;
            while(idx + nums[idx] < N){
                idx += nums[idx];
            }
            cout << (1+idx) << " " << ret << '\n';
        }else{
            cin >> B; nums[idx] = B;
            for(int i = idx; idx/bket == i/bket && i >= 0; i--){
                if((i + nums[i])/bket != i/bket || i + nums[i] >= N){
                    dp[i] = pii(i + nums[i], 1);
                }else{
                    dp[i] = pii(dp[i+nums[i]].f, dp[i+ nums[i]].s + 1);
                }
            }
        }
        
    }

    return 0;
}
