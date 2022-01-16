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

    int N; cin >> N;
    int X; cin >> X; X*=100;

    for(int i = 0; i<N; i++){
        double V, P; cin >> V >> P;
        X -= V * P;
        if(X < 0){
            cout << (i+1); return 0;
        }
    }
    cout << -1;
    return 0;
}
