//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

const int maxa = 5e5 + 23;
int par[maxa];

int main(){
    for(int i = 0; i<maxa; i++) par[i] = i;
    ios_base::sync_with_stdio(false); cin.tie(0);
    int Q; cin >> Q;
    vector<pii> arr(Q);
    for(int i = 0; i<Q; i++){
        int t; cin >> t;
        if(t == 1){
            cin >> arr[i].f; arr[i].s = -1;
        }else{
            cin >> arr[i].f >> arr[i].s;
        }
    }
    
    vector<int> ret;
    for(int i = Q-1; i>=0; i--){
        if(arr[i].s == -1){
            ret.pb(par[arr[i].f]);
        }else{
            par[arr[i].f] = par[arr[i].s];
        }
    }
    reverse(ret.begin(), ret.end());
    for(int i : ret) cout << i << '\n';
    return 0;
}
