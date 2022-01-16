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
        int N, S; cin >> N >> S;
        int sub = (N-1)/2;
         N -= sub;
        // S -= sub;
        cout << S/N << endl;
    }    
    return 0;
}
