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
        ll N; cin >> N;
        if(N <= 6){
            cout << 15 << '\n'; continue;
        }
            N += N%2;
            N *= 10; N /= 4;
            cout << N << '\n';
        
    }    
    return 0;
}
