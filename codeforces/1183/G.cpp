//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define pb push_back
 
#define f first
#define s second

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int Q; cin >> Q;
    while(Q--){
        int N; cin >> N;
        map<int, pii> mp;
        set<int> pos; pos.insert(N);
        for(int i = 0; i<N; i++){
            pos.insert(i);
            int a, b; cin >> a >> b;
            mp[a].f++; mp[a].s += b;
        }
        pii ret;
        vector<pii> all; all.pb(pii(1e9, 0));
        for(auto i : mp){
            swap(i.s.f, i.s.s);
            all.pb(i.s);
            // cout << i.f << " " << i.s.f << " " << i.s.s << endl;
        }

        sort(all.begin(), all.end());
        reverse(all.begin(), all.end());
        for(int i = 1; i<all.size(); i++){
            auto up = pos.upper_bound(all[i].s); --up;
            int val = *up;
            if(val == 0) continue;   
            ret.f += val;
            ret.s += min(val, all[i].f);
            pos.erase(val);
        }
        cout << ret.f << " " << ret.s << '\n';
    }
    return 0;
}
