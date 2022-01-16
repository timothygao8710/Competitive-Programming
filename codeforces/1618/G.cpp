//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

ll get(int l, int r, vector<ll>& pref){
    if(r < l) return 0;
    return l == 0 ? pref[r] : pref[r] - pref[l-1];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int N, M, Q; cin >> N >> M >> Q;
    vector<pii> nums(N + M), edges, qs(Q);
    vector<ll> pref(N+M), ans(Q);

    ll ret = 0;
    for(int i = 0; i<N; i++) cin >> nums[i].f, nums[i].s = 1, ret += nums[i].f;
    for(int i = N; i<N+M; i++) cin >> nums[i].f, nums[i].s = 0;
    sort(nums.begin(), nums.end());
    map<int, pii> intervals;
    intervals[0] = pii(nums[0].s, 0); pref[0] = nums[0].f;
    for(int i = 1; i<nums.size(); i++) {
        intervals[i] = pii(nums[i].s, i);
        edges.pb(pii(nums[i].f - nums[i-1].f, i-1));
        pref[i] = pref[i-1] + nums[i].f;
    }
    // cout << pref[4] << " " << pref[2] << " " << get(3,4,pref) << endl;
    for(int i = 0; i<Q; i++){
        cin >> qs[i].f; qs[i].s = i;
    }
    // for(pii i : nums) cout << i.f << " ";
    cout << endl;
    int idx = 0;
    sort(edges.begin(), edges.end());
    sort(qs.begin(), qs.end());
    for(int i = 0; i<Q; i++){
        
        while(idx < edges.size() && edges[idx].f <= qs[i].f){
            // cout << " sheesh " << edges[idx].f << endl;
            //index is second
            int lbound = edges[idx].s;
            
            int l = (*(--intervals.upper_bound(lbound))).f;
            pii r = intervals[lbound + 1];
            
            // cout << lbound << " " << intervals[l].s << endl;
            // cout << l << " " << lbound << " " << lbound+1 << " " << r.s << endl;
            assert(intervals[l].s == lbound);
            ret -= get(lbound - intervals[l].f + 1, lbound, pref);
            ret += get(r.s - r.f - intervals[l].f + 1, r.s - r.f, pref);
            // cout << (r.s - r.f - intervals[l].f + 1) << " " << (r.s - r.f) << " " << get(r.s - r.f - intervals[l].f + 1, r.s - r.f, pref) << " " << get(3, 4, pref) << endl;
            assert(intervals.count(lbound + 1));
            intervals.erase(lbound + 1);
            intervals[l] = pii(r.f + intervals[l].f, r.s);
            // cout << l <<  " " << intervals[l].s << " " << intervals[l].f << endl;
            idx++;
        }
        ans[qs[i].s] = ret;
    }
    for(ll i : ans){
        cout << i << '\n';
    }
    return 0;
}
