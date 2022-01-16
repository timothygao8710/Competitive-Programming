//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

ll ok(vector<ll>& locs, ll len){
    ll tot = 0; int N = locs.size();
    for(int i = 0; i<N; i++){
        if(i == N-1) {
            tot += len;
        }else{
            tot += min(locs[i] + len, locs[i+1]) - locs[i];
        }
    }
    return tot;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N; ll H; cin >> N >> H;
        ll l = 1, r = 1e18;
        vector<ll> locs(N);
        for(int i = 0; i<N; i++) cin >> locs[i];
        while(l < r){
            ll mid = (l+r)/2;
            if(ok(locs, mid) >= H){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        cout << r << '\n';
    }
    return 0;
}
