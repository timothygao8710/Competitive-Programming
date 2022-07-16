//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

void solve(){
    int N; cin >> N;
    int ok = 1;
    int last; cin >> last;
    for(int i = 1; i<N; i++){
        int cur; cin >> cur;
        ok = ok && cur % last == 0;
        cur = last;
    }
    cout << (ok ? "YES" : "NO") << '\n';
}
//one of the best div2 As ever?
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    while(T--){
        solve();
    }
    
    return 0;
}
