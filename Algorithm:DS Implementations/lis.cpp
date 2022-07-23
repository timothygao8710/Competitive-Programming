//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

vector<int> lis(vector<int>& nums, int strict = 1){
    vector<int> ret;
    for(int i : nums){
        auto it = strict ? 
            lower_bound(ret.begin(), ret.end(), i) : 
            upper_bound(ret.begin(), ret.end(), i);
        if(it == ret.end()){
            ret.pb(i);
        }else{
            *it = 
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int> nums(5);
    nums.pb(0);
    return 0;
}
