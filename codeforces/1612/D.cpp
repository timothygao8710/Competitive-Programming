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
        //r - l : useles
        //r - r : useless
        //only r - l useful, leads to repeat
        ll a, b, x; cin >> a >> b >> x;
        int good = a == x || b == x;
        while(a != b && (a >= x || b >= x)){
            if(b > a) swap(a, b);   
            if(b == 0) break;
            good = good || ((a-x)%b == 0);
            a = a%b; //gcd be like
            // cout << a << " " << b << endl;
        }
        cout << (good ? "YES" : "NO") << '\n';
    }    
    return 0;
}
