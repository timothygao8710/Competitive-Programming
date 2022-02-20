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
        vector<int> nums(N);
        for(int i = 0; i<N; i++) cin >> nums[i];
        int m = 0;
        for(int i = 1; i<N-1; i++){
            if(nums[i-1] < nums[i] && nums[i+1] < nums[i]){
                if(i+2 < N) nums[i+1] = nums[i+2];
                nums[i+1] = max(nums[i+1], nums[i]); m++;
            }
        }
        cout << m << '\n';
        for(int i : nums) cout << i << " ";
        cout << '\n';
    }    
    return 0;
}
