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
    set<int> all; all.insert(-1); all.insert(N);
    map<int, vector<int>> pos;
    int a;
    for(int i=0; i<N; i++){
        cin >> a; pos[a].pb(i);
    }
    ll ret = 0;
    for(auto i : pos){
        for(int j : i.s){
            ll l = *(--all.lower_bound(j));
            ll r = *(all.upper_bound(j));
            ret = max(ret, (r - l - 1)*i.f);
        }
        for(int j : i.s){
            all.insert(j);
        }
    }
    cout << ret;
    return 0;
}
