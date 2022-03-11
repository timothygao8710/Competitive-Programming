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
        int N; cin >> N;
        if(N == 1){
            cout << N << '\n'; continue;
        }
            int cnt = 1 ^ (N%3 == 1);
            while(N > 0){
                cout << (1+cnt);
                N -= 1 + cnt;
                cnt ^= 1;
            }
            cout << '\n';
        
    }    
    return 0;
}
