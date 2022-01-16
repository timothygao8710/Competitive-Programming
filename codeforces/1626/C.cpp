//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second
ll calc(int x){
    return (ll)(x)*(x+1)/2;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vector<int> times(N), health(N);
        vector<pii> inters(N);
        for(int i = 0; i<N; i++) cin >> times[i];
        for(int i = 0; i<N; i++){
            int a; cin >> a;
            inters[i] = pii(times[i] - a + 1, times[i]);
        }
        sort(inters.begin(), inters.end());
        ll sum = 0;
        int r = -1, sz = 0;
        for(pii i : inters){
            if(i.f > r){
                sum += calc(sz);
                r = i.s, sz = i.s - i.f + 1;
            }
            if(i.s > r){
                sz += i.s - r; r = i.s;
            }
            // cout << sum << endl;
        }
        // cout << inters[0].f << " " << inters[0].s << " " << r << " " << sz << endl;
        sum += calc(sz);
        cout << sum << '\n';
    }    
    return 0;
}
