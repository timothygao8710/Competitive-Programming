//Author: timg8710

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define pb push_back

#define f first
#define s second

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    ll a, b; cin >> N;
    pii nums[N];
    for(int i = 0; i<N; i++){
        cin >> a >> b;
        nums[i] = pii(b, a);
    }
    sort(nums, nums+N);
    //discount : needed
    ll ret = 0, items = 0;
    int l = 0, r = N-1;
    while(l <= r){
        while(nums[r].s < nums[l].f - items && l <= r){
            items += nums[r].s;
            ret += 2*(nums[r].s);
            r--;
        }
        if(l > r) break;
        nums[r].s -= nums[l].f- items; 
        ret += 2*(nums[l].f - items);
        items = nums[l].f;
        // cout << l << " " << r << " " << items << endl;
        while(nums[l].f <= items && l <= r){
            ret += nums[l].s; items += nums[l].s; l++;
        }
        // cout << l << " " << r << " " << items << endl;
    }
    cout << ret;
}
