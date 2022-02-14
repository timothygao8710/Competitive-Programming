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
        int N; cin >> N;
        vector<int> nums(N), suf(N+1); suf[N] = 1e9;
        for(int i = 0; i<N; i++) cin >> nums[i];
        for(int i = N-1; i>=0; i--) suf[i] = min(nums[i], suf[i+1]);
        int cur = 0, ret = 0;
        for(int i = 0; i<N; i++){
            if(nums[i] > cur){
                if(suf[i+1] >= cur) ret++;
                cur = nums[i];
            }
        }
        cout << ret << '\n';
    }    
    return 0;
}
