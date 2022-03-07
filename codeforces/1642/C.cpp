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
        int N, X; cin >> N >> X;
        vector<ll> nums(N);
        for(int i = 0; i<N; i++) cin >> nums[i];
        sort(nums.begin(), nums.end());
        multiset<ll> look;
        for(ll i : nums){
            if(look.count(i)) {
                look.erase(look.find(i)); continue;
            }
            look.insert(i*X);
        }
        cout << look.size() << '\n';
    }    
    return 0;
}
