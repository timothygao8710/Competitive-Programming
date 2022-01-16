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
        cin >> N; N--;
        if(N/2 == 2){
            cout << 2 <<  " " << 4 << endl; continue;
        }
        cout << 2 << " " << (N/2) << endl;
    }    
    return 0;
}
