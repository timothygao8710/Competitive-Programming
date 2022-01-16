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
        vector<int> nums(N); map<int, int> same;
        for(int i = 0; i<N; i++) cin >> nums[i], same[nums[i]]++;
        sort(nums.begin(), nums.end());
        ll ret = 0;
        int idx = 0;
        vector<int> stack;
        cout << same[0] << " ";
        for(int i = 1; i<=N; i++){
            while(idx < N && nums[idx] < i){
                stack.pb(nums[idx]); idx++; 
            }
            if(ret == -1 || stack.empty()) {
                ret = -1;
                cout << -1 << " ";
            }else{
                ret += i-1-stack[stack.size()-1]; stack.pop_back();
                cout << ret + same[i] << " ";
            }
        }
        cout << '\n';
    }    
    return 0;
}
