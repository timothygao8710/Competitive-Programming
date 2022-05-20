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
    int N; cin >> N;
    while(N--){
        ll a; cin >> a;
        if(a%2){
            cout << -1 << '\n'; continue;
        }
        a /= 2;
        if(a<2){
            cout << -1 << '\n'; continue;
        }
        cout << (a/3 + (a%3 != 0) ) << " " << a/2 << '\n';
    }
    return 0;
}
