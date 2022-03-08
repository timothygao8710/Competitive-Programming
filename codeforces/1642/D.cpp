//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

void solve(){
    int N; cin >> N;
    vector<int> nums(N); map<int, int> mp;
    for(int i = 0; i<N; i++) cin >> nums[i], mp[nums[i]]++;
    for(auto i : mp){
        if(i.s%2) {
            cout << -1 << endl; return;
        }
    }
    vector<pii> ret; vector<int> lens;
    auto addX = [&](int loc, int x){
        nums.insert(nums.begin() + loc, x);
        nums.insert(nums.begin() + loc, x);
        ret.pb(pii(loc, x));
    };
    for(int i = 0; i<(int)(nums.size());){
        int loc = -1;
        for(int j = i+1; j<(int)(nums.size()); j++){
            if(nums[i] == nums[j]) {
                loc = j; continue;
            }
        }
        assert(loc != -1);
        lens.pb(2*(loc-i));
        for(int j = 1; j<loc-i; j++){
            if(loc + j >= (int)(nums.size()) || nums[i+j] != nums[loc+j]){
                addX(loc+j, nums[i+j]);
            }
        }
        i = i + 2*(loc-i);
    }
    cout << ret.size() << endl;
    for(pii i : ret){
        cout << i.f << " " << i.s << '\n';
    }
    cout << lens.size() << endl;
    for(int i : lens){
        cout << i << '\n';
    }
    // cout << endl;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
