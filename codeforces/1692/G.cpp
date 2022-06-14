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
        int N, K; cin >> N >> K;
        vector<int> nums(N);
        for(int i = 0; i<N; i++) cin >> nums[i];
        int ok = 0, ret = 0;

        for(int i = 1; i<N; i++){
            if(nums[i-1] >= nums[i]*2){
                ok = i;
            }
            if(i - ok >= K){
                ret++;
            }
        }

        cout << ret << '\n';
    }    
    return 0;
}
