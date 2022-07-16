//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

//gcd(a,b) <= min(a,b)
void solve(){
    int N, l, r; cin >> N >> l >> r;
    int ok = 1;
    vector<int> ret;
    for(int i = 1; i<=N; i++){
        if(i > r){
            ok = 0; break;
        }
        if(l <= i && i <= r){
            ret.pb(i); continue;
        }
        int cur = (i - l % i)%i;
        if(l + cur <= r){
            ret.pb(l + cur);
        }else{
            ok  =0; break;
        }
    }
    if(ok){
        cout << "YES" << "\n";
        for(int i : ret){
            cout << i << " ";
        }
        cout << '\n';
    }else{
        cout << "NO\n";
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    while(T--){
        solve();
    }
    
    return 0;
}
