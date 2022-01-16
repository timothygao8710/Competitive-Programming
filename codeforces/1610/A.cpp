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
        int N, M; cin >> N >> M;
        if(N == 1 && M == 1){
            cout << 0 << endl; continue;
        }
        if(N == 1 || M == 1){
            cout << 1 << endl;
        }else{
            cout << 2 << endl;
        }
    }

    return 0;
}
