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
    int N, Q; cin >> N >> Q;
    ll sum = 0, cur = 0;
    map<ll, ll> mp;
    for(int i = 0; i<N; i++){
        cin >> mp[i]; sum += mp[i];
    }    
    while(Q--){
        int t; cin >> t;
        if(t == 1){
            //set
            ll i, x, n; cin >> i >> x; i--;
            n = x - cur;
            sum += n - mp[i];
            mp[i] = n;
            // cout << "WHY " << n << endl;
        }else{
            //reset
            cin >> cur;
            sum = cur * N;
            mp.clear();
        }
        cout << sum << '\n';
    }
    return 0;
}
