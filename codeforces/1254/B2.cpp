//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

const int maxa = 1e6 + 134;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int N; cin >> N;
    vector<ll> nums(N);
    for(int i = 0; i<N; i++){
        cin >> nums[i]; 
        if(i != 0) nums[i] += nums[i-1];
    }
    vector<ll> primes;
    for(ll i = 2; i*i <= nums[N-1]; i++){
        if(nums[N-1]%i == 0) {
            primes.pb(i);
        }
        while(nums[N-1]%i == 0){
            nums[N-1] /= i;
        }
    }
    if(nums[N-1] != 1) primes.pb(nums[N-1]);
    nums[N-1] = 0;
    ll best = -1;
    for(ll i : primes){
        ll cur = 0;
        for(ll j : nums){
            cur += min(j%i, i - j%i);
        }
        best = best == -1 ? cur : min(best, cur);
    }
    cout << best;
    return 0;
}
