//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second
ll binpow(ll base, ll pow)
{
    ll ret = 1;
    while(pow > 0){
        if(pow & 1) ret = (ret * base);
        base = (base * base);
        pow >>= 1;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
    ll ret = 0, mx = 1, pow = 0;
    int N; cin >> N;
    for(int i = 0; i<N; i++){
        ll a; cin>>a;
        while(a%2==0){
            pow++; a/=2;
        }
        mx = max(mx, a); ret += a;
    }
    // cout << mx << " " << pow << endl;
    cout << (mx * binpow(2, pow) + ret - mx) << '\n';
    }
    return 0;
}
