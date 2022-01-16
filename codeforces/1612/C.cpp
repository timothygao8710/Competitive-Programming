//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

ll triangle(ll len){
    return (1+len)*len/2;
}

ll calc(ll cur, ll K){
    if(cur <= K){
        return triangle(cur);
    }
    ll ret = triangle(K);
    ret += triangle(K-1) - triangle(2*K - 1 - cur);
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        ll K, X; cin >> K >> X; 
        ll l = 0, r = 2*K - 1;
        while(l < r){
            ll mid = (l+r)/2; 
            if(calc(mid, K) >= X){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        cout << l << '\n';
    }    
    return 0;
}
