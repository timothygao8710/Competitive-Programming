//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

const int bkt = 300, maxn = 1e5+10;
int dp[bkt][maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, Q, P, K; cin >> N;
    vector<int> nums(N);
    for(int i = 0; i<N; i++){
        cin >> nums[i];
    }

    for(int i = 0; i<bkt; i++){
        for(int j = N-1; j>=0; j--){
            dp[i][j] = (j + i + nums[j] >= N) ? 0 : dp[i][j + i + nums[j]];
            dp[i][j]++;
        }
    }
    cout << endl;
    cin >> Q;

    while(Q--){
        cin >> P >> K; P--;
        int ret = 0;
        if(K > bkt-1){
            while(P < N){
                P = nums[P] + K + P; ret++;
            }
        }else{
            ret = dp[K][P];
        }
        cout << ret << '\n';
    }

    return 0;
}
