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
    vector<int> mns, mxs; 
    ll ret = 0;
    ll prev = 0;
    for(int i = 0; i<N; i++){
        int n; cin >> n; int good = 1;
        int mx = -1, mn = 1e9;
        for(int j = 0; j<n; j++){
            int a; cin >> a;
            if(a > mn){
                good = 0;
            }
            mn = min(mn, a); mx = max(mx, a);
        }
        if(!good){
            // cout << "WHY" << endl;
            ret += 2*N-1-2*prev; prev++; continue;

        }
        // cout << i << "  " << mx << endl;
        mns.pb(mn), mxs.pb(mx);
    }
    sort(mns.begin(), mns.end());
    sort(mxs.begin(), mxs.end());
    int j = 0;
    for(int i : mns){
        // cout << j << " " << mxs[j] << " " << i << endl;
        while(j < mxs.size() && mxs[j] <= i) j++;
        ret += mxs.size() - j;
    }
    cout << ret;
    return 0;
}
