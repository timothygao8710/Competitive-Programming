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
    int N, sum = 0, ret = 1000000; cin >> N;
    vector<int> nums(N);
    for(int i =0; i<N; i++){
        cin >> nums[i]; sum += nums[i];
    }
    for(int i = 0; i<N; i++){
        if(i != 0) nums[i] += nums[i-1];
        ret = min(ret, abs(sum - 2*nums[i]));
    }
    cout << ret;
    return 0;
}
