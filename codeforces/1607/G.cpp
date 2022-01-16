//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;
 
#define pb push_back
 
#define f first
#define s second

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        ll N, M; cin >> N >> M;
        ll freedom = 0, delta = 0;
        vector<pii> nums(N);
        for(int i = 0; i<N; i++){
            cin >> nums[i].f >> nums[i].s;
            freedom += min(min(M, nums[i].f), min(nums[i].s, nums[i].f + nums[i].s - M));
            if(nums[i].f >= M){
                delta += nums[i].f - M - nums[i].s;
            }else{
                delta -= nums[i].s - (M-nums[i].f);
            }
        }
        if(delta > 0){
            cout << delta << '\n';
        }else{
            cout << max(-delta%2, -delta - 2*freedom) << '\n';
        }

        for(int i = 0; i<N; i++){
            ll cur = min(nums[i].f, min(nums[i].s, nums[i].f + nums[i].s - M)); cur = min(cur, M);
            cur = min(cur, max(0ll, -delta/2)); delta += 2*cur;
            ll left = min(nums[i].f, M) - cur;
            cout << left << " " << (M - left) << '\n';
        }
    }
    return 0;
}
/*
4
0 2
0 2
2 0
2 0
*/