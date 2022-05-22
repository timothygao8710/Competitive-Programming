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
        map<int, int> mp;
        for(int i = 0; i<N; i++){
            cin >> nums[i];
            mp[nums[i]]++;
        }
        int singles = 0;
        for(auto i : mp){
            if(i.s == 1){
                singles++;
            }
        }
        cout << (mp.size()-singles + (singles+1)/2) << '\n';
    }    
    return 0;
}
