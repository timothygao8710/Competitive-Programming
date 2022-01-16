//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

int good(vector<int>& nums){
    int good = 1;
    for(int i = 0; i<nums.size(); i++){
        good = good && nums[i] == nums[nums.size()-1-i];
    }
    return good;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N; cin >> N; vector<int> nums(N), a, b;
        for(int i  = 0; i<N; i++) cin >> nums[i];
        int ok = 1;
        for(int i = 0; i<N/2; i++){
            if(nums[i] != nums[N-1-i]){
                for(int j : nums){
                    if(j != nums[i]){
                        a.pb(j);
                    }
                    if(j != nums[N-1-i]){
                        b.pb(j);
                    }
                }
                ok = good(a) || good(b);
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
