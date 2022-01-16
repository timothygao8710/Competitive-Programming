//Author: timg8710

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

#define pb push_back

#define f first
#define s second

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll N, inv, x; cin >> N >> inv >> x;
    ll nums[N], diffs[N-1];
    for(int i = 0; i<N; i++) cin >> nums[i];
    sort(nums, nums+N);
    // cerr << "sdf" << endl;
    for(int i = 1; i<N; i++){
        diffs[i-1] = nums[i] - nums[i-1]-1;
    }
    sort(diffs, diffs + N - 1);
    ll ret = N;
    for(int i = 0; i<N-1; i++){
        ll need = max((ll)0,diffs[i]/x);
        if(need <= inv){
            inv -= need; ret--;
        }
    }
    cout << ret;
}
