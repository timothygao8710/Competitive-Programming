//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

void solve(){
    int N, K; cin >> N >> K;
    int tot = K-1;
    vector<int> nums(N), sorted(N);
    for(int i = 0; i<N; i++){
        cin >> nums[i]; sorted[i] = nums[i];
    }
    sort(sorted.begin(), sorted.end());
    array<int, 3> best = {(int)1e9, -1, -1};
    K += (N-K+1)/2;
    for(int i = 0; i+K-1<N; i++){
        best = min(best, {sorted[i+K-1] - sorted[i], sorted[i], sorted[i+K-1]});
    }
    cout << best[1] << " " << best[2] << '\n';
    int last = 0, run = 0;
    for(int i = 0; i<N && tot; i++){
        run += (nums[i] >= best[1] && nums[i] <= best[2] ? 1 : -1);
        if(run > 0){
            cout << (last+1) << " " << i+1 << '\n';
            last = i+1, tot--, run = 0;
        }
    }
    assert(last < N);
    cout << last+1 << " " << N << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        solve();
    }    
    return 0;
}
