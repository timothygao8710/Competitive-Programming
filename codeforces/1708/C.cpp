//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

void solve(){
    int N, S; cin >> N >> S;

    vector<int> nums(N), ret(N);
    for(int i = 0; i<N; i++) cin >> nums[i];
    
    int cur = 0;
    for(int i = N-1; i>=0; i--){
        if(nums[i] > cur){
            if(cur < S) {
                ++cur; ret[i] = 1;
            }
        }else{
            ret[i] = 1;
        }
    }
    for (int i : ret) cout << i;
    cout << '\n';
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    while(T--){
        solve();
    }
    
    return 0;
}
