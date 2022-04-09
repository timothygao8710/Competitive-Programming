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
    int N; ll K; cin >> N >> K;
    //back to front
    vector<ll> takes(N), rem(N), nums(N), starts(N);
    ll ret = 0;
    for(int i = 0; i<N; i++) cin >> nums[i];
    for(int i = N-1; i>=0; i--){
        K = min(K, i+1LL);
        if(i != N-1) {
            nums[i] -= rem[i+1] - takes[i+1];
            rem[i] += rem[i+1] - takes[i+1];
        }
        // cout << "premature: " << rem[i] << endl;
        if(nums[i] > 0) {
            ll mult = (nums[i]+K-1)/K;
            // cout << mult << " " << K << " " << nums[i] << endl;
            starts[i] = mult;
            takes[i] += mult;
            takes[max(0LL, i-K)]-=mult;
            rem[i] += mult * K;
        }
        if(i != N-1) {
            // cout << i << " " << takes[i] << endl;
            takes[i] += takes[i+1];
        }
        // cout << i << " " << rem[i] << " " << (nums[i] + K - 1)/K*K << " " << takes[i] << endl;
    }    
    for(ll i : starts) ret += i;
    // for(auto i : starts){
    //     cout << i << " ";
    // }
    // cout << endl;
    cout << ret << '\n';
    return 0;
}
