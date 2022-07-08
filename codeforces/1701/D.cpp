//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

pii getRange(int i, int bi){
    return pii(i/(bi + 1) + 1, i/bi);
}

void solve(){
    int N; cin >> N;
    //ai must be from [l,r] for ith bi
    vector<int> ret(N+1);
    vector<array<int,3>> ranges;
    for(int i = 1; i<=N; i++){
        int x; cin >> x;
        if(x == 0){
            ranges.pb({i+1, N, i});
        }else{
            pii cur = getRange(i, x);
            ranges.pb({cur.f, cur.s, i});
        }
    }
    sort(ranges.begin(), ranges.end());
    set<pii> soon; //ending the soonest
    int idx = 0;
    for(int i = 1; i<=N; i++){
        while(idx < N && ranges[idx][0] <= i){  
            soon.insert(pii(ranges[idx][1], ranges[idx][2]));
            idx++;
        }
        assert(!soon.empty());
        pii cur = *soon.begin();
        soon.erase(cur);
        ret[cur.s] = i;
    }

    for(int i = 1; i<=N; i++){
        cout << ret[i] << " ";
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        solve();
    }    
    return 0;
}
