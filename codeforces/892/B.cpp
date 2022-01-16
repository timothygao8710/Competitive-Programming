//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    vector<int> nums(N), mark(N);
    for(int i = 0; i<N; i++){
        cin >> nums[i]; mark[max(0, i-nums[i])]++;
    }
    int ret = 0;
    int cur = 0;
    for(int i : mark){
        cur += i;
        cur--;
        ret += (cur == 0);
    }
    cout << ret;
    return 0;
}
