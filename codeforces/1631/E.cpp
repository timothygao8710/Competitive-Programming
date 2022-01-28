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
    vector<int> nums(N), last(N+1);
    for(int i = 0; i<N; i++) cin >> nums[i], last[nums[i]] = i;
    int r = -1, ret = 0;
    for(int i = 0; i<N;){
        if(i > r){
            ret++;
            r = last[nums[i]];
            if(r == i){
                i++; continue;
            }
        }
        int j = i, nr = -1;
        for(; j<=r; j++){
            nr = max(nr, last[nums[j]]);
        }
        assert(nr >= r);
        r = nr;
        ret++;
        // cout << i << " " << r << " " << ret << " " << j << endl;
        i = j;
    }
    cout << N-ret;
    return 0;
}
