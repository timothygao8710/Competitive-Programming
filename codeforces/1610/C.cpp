//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

int good(vector<pii>& nums, int take){
    int idx = 1;
    for(pii i : nums){
        if(i.f >= take - idx && i.s >= idx-1){
            idx++;
        }
    }
    return idx > take;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vector<pii> nums(N);
        for(int i = 0; i<N; i++){
            cin >> nums[i].f >> nums[i].s;
        }
        int l = 1, r = N;
        while(l < r){
            int mid = (l+r+1)/2;
            if(good(nums, mid)){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        cout << l << '\n';
    }    
    return 0;
}
