//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

ll ggcd(int a, int b){
    return (a == 0 || b == 0 ? a + b : gcd(max(a,b)%min(a,b), min(a,b)));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T, N; cin >> T;
    while(T--){
        cin >> N; int a, b;
        for(int i = 0; i<N/2; i++){
            cin >> a >> b;
            int am = 1, bm = 1;
            if(b < 0) bm = -1;
            if(a < 0) am = -1;
            cout << (b) << " " << (-a) << " ";
        }
        cout << "\n";
    }
    return 0;
}
