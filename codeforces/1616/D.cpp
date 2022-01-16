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
        int N, X; cin >> N;
        vector<ll> nums(N);
        for(int i= 0; i<N ;i++) cin >> nums[i];
        cin >> X;
        for(int i = 0; i<N; i++) nums[i] -= X;
        int ret = 0;
        ll run = 1e14;
        for(int i = 0; i<N; i++){
            run += nums[i];
            if(run < 0){
                ret++; nums[i] = run = 1e14;
            }
            run = min(run, nums[i]);
            // cout << run << " " << ret << endl;
        }
        cout << N - ret << '\n';
    }    
    return 0;
}
