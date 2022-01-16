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
    ll T, N, dist, time; cin >> T;
    while(T--){
        cin >> N >> dist >> time;
        if(N*dist <= time){
            cout << N*(N-1)/2 << "\n"; continue;
        }else{
            ll each = time/dist;
            cout << max((ll)0,(N-each)*each) + (each)*(each-1)/2 << "\n";
        }
    }    
    return 0;
}
