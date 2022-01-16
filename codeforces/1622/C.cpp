//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        ll N, K; cin >> N >> K;
        vector<ll> nums(N);
        ll sum = 0;
        for(int i = 0; i<N; i++) cin >> nums[i], sum += nums[i];
        if(sum <= K){
            cout << 0 << '\n'; continue;
        }
        if(K == sum-1){
            cout << 1 << '\n'; continue;
        }
        if(N == 1){
            cout << nums[0] - K << '\n'; continue;
        }
        sort(nums.begin(), nums.end()); 
        ll ret = LLONG_MAX; sum -= nums[0];
        for(int i = N-1; i>=1; i--){
            sum -= nums[i];
            ll back = N-i;
            ll x = (K - sum)/(back+1); 
            if(K - sum < 0 && (K-sum)%(back+1) != 0){
                x--;
            }
            assert(back * x + x <= K - sum);
            // cout << x << "X" << endl;
            ret = min(ret, back + max(0ll, nums[0] - x));
        }
        cout << (ret) << '\n';
    }    
    return 0;
}
