//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    while(T--){
        int a, b, c; cin >> a >> b >> c;
        int dev = a + c - 2*b; dev = abs(dev);
        cout << min(1, dev%3) << '\n';
    }

    return 0;
}
