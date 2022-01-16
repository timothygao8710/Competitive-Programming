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
    int T; cin >> T;
    while(T--){
        int N, left, right; cin >> N >> left >> right;
        set<int> all; int good = 1;
        vector<int> l, r;
        for(int i = 1; i<=N; i++) all.insert(i);
        l.pb(left), r.pb(right); all.erase(left); all.erase(right);
        
        for(int i = 1; i<N/2; i++){
            int cur = *(all.begin()); all.erase(cur);
            r.pb(cur);
            if(cur > right){
                good = 0;
            }
        }

        for(int i = 1; i<N/2; i++){
            int cur = *(all.begin()); all.erase(cur);
            l.pb(cur);
            if(cur < left){
                good = 0;
            }
        }

        if(!good){
            cout << -1 << endl; continue;
        }
        for(int i : l) cout << i << " ";
        for(int i : r) cout << i << " ";
        cout << '\n';
    }       
    return 0;
}
