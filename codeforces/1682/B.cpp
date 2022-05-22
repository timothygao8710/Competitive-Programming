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
        vector<int> nums(N), og(N);
        for(int i = 0; i<N; i++) cin >> nums[i], og[i] = nums[i];
        sort(nums.begin(), nums.end());
        int ret = (1<<29) - 1;
        for(int i = 0; i<N; i++){
            if(og[i] != nums[i]){
                ret &= nums[i];
            }
        }
        cout << ret << '\n';
    }    
    return 0;
}
