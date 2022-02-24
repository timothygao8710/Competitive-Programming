//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

const int mod = 998244353;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N, M, K, Q; cin >> N >> M >> K >> Q;
        vector<pii> nums(Q);
        for(int i = 0; i<Q; i++) cin >> nums[i].f >> nums[i].s;
        set<int> takenN, takenM;
        ll ret = 1;
        for(int i = Q-1; i>=0; i--){
            if((int)(takenN.size()) == N || (int)(takenM.size()) == M) continue;
            if(takenN.count(nums[i].f) && takenM.count(nums[i].s)) continue;
            takenN.insert(nums[i].f), takenM.insert(nums[i].s);
            ret *= K; ret %= mod;
        }
        cout << ret << '\n';
    }
    return 0;
}
