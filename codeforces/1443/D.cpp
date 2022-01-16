//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vector<int> nums(N); 
        for(int i = 0; i<N; i++) cin >> nums[i];
        int mn = nums[0], ok = 1; nums[0] = 0;
        for(int i = 1; i<N; i++){
            int rem = min(mn, nums[i] - nums[i-1]);
            // cout << rem << endl;
            mn = min(rem, mn);
            nums[i] -= rem;
            if(nums[i] < nums[i-1] || rem < 0) ok = 0;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
