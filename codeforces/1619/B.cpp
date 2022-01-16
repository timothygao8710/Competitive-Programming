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
    vector<ll> all;
    set<ll> temp;
    for(ll i = 1; i<32000; i++){
        all.pb(i*i*i); temp.insert(i*i*i);
        if(!temp.count(i*i)) all.pb(i*i); 
    }
    sort(all.begin(), all.end());
    int T; cin >> T;
    while(T--){
        ll x; cin >> x;
        auto it = upper_bound(all.begin(), all.end(), x);
        cout << (it - all.begin()) << endl;
    }
    return 0;
}
