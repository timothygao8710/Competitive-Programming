//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

//this contest is literally spam parity...

//bicolor a eularian circuit
//greedy works because 
//1. in-out means deg-=2, so at any stage all deg but initial is even
//2. Tour stops when no out, only happens on inital start(which gets subtracted 1, becoming odd)

const int maxn = 2e5 + 10;
vector<pii> toarr[maxn], toval[maxn];
vector<int> visa[maxn], visb[maxn];
vector<char> ret[maxn];

void solve(int cur){
    while(!toval[cur].empty()){
        // cout << cur << endl;
        while(visa[cur][visa[cur].size()-1]){
            visa[cur].pop_back();
            toval[cur].pop_back();
            if(toval[cur].empty()) break;
        }
        if(toval[cur].empty()) break;
        pii nxt = toval[cur][toval[cur].size()-1];
        toval[cur].pop_back();
        visa[cur].pop_back();
        ret[cur][toval[cur].size()] = 'L';
        assert(toval[cur].size() == visa[cur].size());
        visb[nxt.f][nxt.s] = 1;
        // cout << "HERE" << endl;
        while(visb[nxt.f][visb[nxt.f].size()-1]){
            visb[nxt.f].pop_back();
            toarr[nxt.f].pop_back();
            assert(!visb[nxt.f].empty());
        }
        assert(visb[nxt.f].size() == toarr[nxt.f].size());
        // cout << "HERE" << endl;
        assert(!visb[nxt.f].empty());
        int temp = nxt.f;
        nxt = toarr[nxt.f][visb[nxt.f].size()-1];
        visb[temp].pop_back();
        toarr[temp].pop_back();

        ret[nxt.f][nxt.s] = 'R';
        visa[nxt.f][nxt.s] = 1;
        cur = nxt.f;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int M; cin >> M;
    map<int, int> mp;
    for(int i = 0; i<M; i++){
        int N; cin >> N;
        visa[i].resize(N);
        ret[i].resize(N);
        for(int j = 0; j<N; j++){
            int a; cin >> a;
            if(!mp.count(a)) mp[a] = (int)(mp.size());
            toval[i].pb(pii(mp[a], toarr[mp[a]].size()));
            toarr[mp[a]].pb(pii(i, j));
            visb[mp[a]].pb(0);
        }
    }

    for(int i = 0; i<maxn; i++){
        if(toarr[i].size()%2 || toval[i].size()%2) {
            cout << "NO" << endl; return 0;
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i<M; i++){
        solve(i);
    }
    
    for(int i = 0; i<M; i++){
        for(char j : ret[i]){
            cout << j;
        }
        cout << '\n';
    }
    return 0;
}
