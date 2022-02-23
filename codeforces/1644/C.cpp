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
    // cout << (int)(5e9) << endl;
    int T; cin >> T;
    while(T--){
        int N, K; cin >> N >> K;
        vector<ll> nums(N), ret(N+1);
        fill(ret.begin()+1, ret.end(), -1e13);
        for(int i = 0; i<N; i++) cin >> nums[i];
        for(int i = 0; i<N; i++){
            ll cur = 0;
            for(int j = i; j<N; j++){
                cur += nums[j];
                ret[j-i+1] = max(ret[j-i+1], cur);
            }
        }
        for(int i = N-1; i>=0; i--) ret[i] = max(ret[i], ret[i+1]);
        for(int i = 0; i<=N; i++){
            ret[i] += (ll)i*K; 
            if(i != 0) ret[i] = max(ret[i], ret[i-1]);
            cout << ret[i] << " ";
        }
        cout << '\n';
    }    
    return 0;
}
