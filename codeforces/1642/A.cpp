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
        int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
        if(b == d && d > f){
            cout << abs(a-c) << endl;
            continue;
        }
        if(d == f && d > b){
            cout << abs(c - e) << endl; continue;
        }
        if(b == f && b > d){
            cout << abs(a - e) << endl; continue;
        }
        cout << 0 << endl;
        
    }
    return 0;
}
