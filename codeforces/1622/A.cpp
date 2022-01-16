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
        vector<int> nums(3);
        for(int i = 0; i<3; i++) cin >> nums[i];
        sort(nums.begin(), nums.end());
        if(nums[0] + nums[1] ==  nums[2]){
            cout << "YES" << '\n'; continue;
        }
        if(nums[0] == nums[1] && nums[2]%2 == 0){
            cout << "YES" << '\n'; continue;
        }
        if(nums[1] == nums[2] && nums[0]%2 == 0){
            cout << "YES" << '\n'; continue;
        }
        cout << "NO" << '\n';
    }    
    return 0;
}
