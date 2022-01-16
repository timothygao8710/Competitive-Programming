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
    ll a, b, ret = LLONG_MAX; cin >> a >> b;

    for(ll i = 2; i*i<=b; i++){
        if(b%i) continue;
        ll pow = 0;
        while(b%i == 0){
            b /= i; pow++;
        }
        ll t = a, cur = 0;
        while(t/i > 0){
            cur += t/i; t/=i;
        }
        ret = min(ret, cur/pow);
    }

    if(b == 1){
        cout << ret; return 0;
    }

    ll t = a, cur = 0;
    while(t/b > 0){
        cur += t/b; t/=b;
    }
    ret = min(ret, cur);
    cout << ret;
    return 0;
}
