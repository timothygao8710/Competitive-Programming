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
        int N; cin >> N; ll ret = 0;
        int nums[N+2]; nums[0] = nums[N+1] = 0;
        for(int i = 1; i<=N; i++){
            cin >> nums[i];
            ret += abs(nums[i] - nums[i-1]);
        }
        ret += nums[N];
        for(int i = 1; i<=N; i++){
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]){
                ret -= nums[i] - max(nums[i-1], nums[i+1]);
            }
        }
        cout << ret << "\n";
    }    
    return 0;
}
