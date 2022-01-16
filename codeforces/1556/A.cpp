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
        int a, b; cin >> a >> b;
        if(abs(a-b)%2){
            cout << -1 << '\n';
        }else{
            if(a == b){
                if(a == 0){
                    cout << 0 << '\n';
                }else{
                    cout << 1 << '\n';
                }
            }else{
                cout << 2 << '\n';
            }
        }
    }
    return 0;
}
 