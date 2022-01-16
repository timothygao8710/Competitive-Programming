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
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vector<int> a, b;
        for(int i = 0; i<N; i++){
            int c; cin >> c; if(c%2){
                a.pb(i);
            }else{
                b.pb(i);
            }
        }
        if(abs((int)a.size() - (int)b.size()) > 1){
            cout << -1 << '\n'; continue;
        }
        ll res = 1e14;
        if(a.size() == b.size()){
            ll ret = 0;
            for(int i = 0, l = 0, r = 0; i<N; i++){
                if(i%2){
                    ret += max(0, b[r] - i); r++;
                }else{
                    ret += max(0, a[l] - i); l++;
                }
            }
            res = min(res, ret);
        }
        if(b.size() >= a.size()) swap(a, b);
        ll ret = 0;
        for(int i = 0, l = 0, r = 0; i<N; i++){
            if(i%2){
                ret += max(0, b[r] - i); r++;
            }else{
                ret += max(0, a[l] - i); l++;
            }
        }
        res = min(res, ret);

        cout << res << '\n';
    }
    return 0;
}
 