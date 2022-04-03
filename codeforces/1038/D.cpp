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
    int N; cin >> N;
    vector<ll> nums(N);
    ll mn = 1e9, mx = -mn, sumA = 0;
    for(int i = 0; i<N; i++) {
        cin >> nums[i]; 
        mn = min(mn, nums[i]);
        mx = max(mx, nums[i]);
        sumA += abs(nums[i]);
    }
    if(N == 1) {cout << nums[0]; return 0;}

        if(mn > 0){
            sumA -= 2*mn;
            cout << sumA; return 0;
        }
        if(mx < 0){
            sumA += 2*mx;
            cout << sumA; return 0;
        }
        cout << sumA;

    return 0;
}
