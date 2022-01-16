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
    int n, k, x, c;
    cin >> n >> k >> x;
    int vals[1025]; memset(vals, 0, sizeof(vals));
    for(int i = 0; i<n; i++) {
        cin >> c; vals[c]++;
    }
    for(int i = 0; i<k; i++){
        int flat = 1;
        int prev[1025];
        for(int j = 0; j<=1024; j++) prev[j] = vals[j];
        for(int j = 0; j<=1024; j++){
            int rem = prev[j]/2;
            if(prev[j]%2){
                rem += flat;
                flat ^= 1;
            }
            vals[j] -= rem; vals[j^x] += rem;
        }
    }
    for(int i = 1024; i>=0; i--){
        if(vals[i]) {
            cout << i << " "; break;
        }
    }
    for(int i = 0; i<=1024; i++){
        if(vals[i]) {
            cout << i << " "; break;
        }
    }
}
