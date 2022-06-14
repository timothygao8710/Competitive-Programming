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
        map<int, vector<int>> mp;
        for(int i = 0; i<N; i++) {
            cin >> nums[i];
            mp[nums[i]].pb(i);
        }
        int val = 1;
        int ret = nums[0];
        pii range(0,0);
        for(auto i : mp){
            vector<int> v = i.s;
            int n = (int)v.size();
            int cur = 1, last = v[0];
            for(int j = 1; j<n; j++){
                cur -= v[j] - v[j-1] - 1;
                
                if(cur < 0) {
                    last = v[j];
                    cur = 0;
                }
                cur++;
                // cout << cur << " "  << v[j] << endl;
                if(cur > val){
                    // cout << "what " << v[j] << " " << endl;
                    val = cur;
                    ret = i.f;
                    // cout << i.f << endl;
                    range.f = last;
                    range.s = v[j];
                }
            }
        }

        cout << ret << " " << (range.f + 1) << " " << (range.s + 1) << '\n';
    }    
    return 0;
}
