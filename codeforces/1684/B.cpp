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
        ll A, B, C; cin >> A >> B >> C;
        ll Z = C;
        ll Y = B;
        ll X = B * C + A;
        assert(X%Y == A);
        assert(Y%Z == B);
        assert(Z%X == C);
        cout << X << " " << Y << " " << Z << '\n';
    }    
    return 0;
}
