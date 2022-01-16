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
    int T, N; cin >> T;
    while(T--){
        cin >> N; int i = 1;
        for(; i<=N; i++){
            if(i*i >= N) break;
        }
        cout << (i) << endl;
    }
    return 0;
}
