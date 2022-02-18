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
        ll N, start, end; cin >> N >> start >> end;
        for(int i = 0; i<N; i++) {
            ll a; cin >> a; start ^= a;
        }
        cout << (start%2 == end%2 ? "Alice" : "Bob") << '\n';
    }    
    return 0;
}
