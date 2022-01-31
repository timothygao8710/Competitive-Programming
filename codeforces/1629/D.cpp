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
        int N; cin >> N;
        int ok = 0;
        set<string> twos, puretwos, threes;
        for(int i = 0; i<N; i++){
            string cur; cin >> cur;
            string rev = cur;
            reverse(rev.begin(), rev.end());
            if(rev == cur) {
                ok = 1; continue;
            }
            
            if(cur.length() == 2){
                ok = ok || twos.count(cur);
                ok = ok || puretwos.count(cur);
                reverse(cur.begin(), cur.end());
                puretwos.insert(cur); continue;
            }
            // cout << cur.length() << endl;
            ok = ok || threes.count(cur);
            ok = ok || puretwos.count(cur.substr(1,2));
            reverse(cur.begin(), cur.end());
            threes.insert(cur);
            twos.insert(cur.substr(1,2));
        }
        cout << (ok ? "YES": "NO") << '\n';
    }    
    return 0;
}
