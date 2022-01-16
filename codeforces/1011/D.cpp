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
    int r, n, u;
    cin >> r >> n;
    int good[n];
    for(int i = 0; i<n; i++){
        cout << 1 << endl;
        cin >> u;
        if(u == 0) return 0;
        good[i] = u;
    }    
    int idx = 0;
    int l = 1;
    while(l <= r){
        int mid = (l+r)/2;
        cout << mid << endl;
        cin >> u; assert(u != -2);
        if(u == 0){
            return 0;
        }
        u *= good[idx]; idx = (idx+1)%n;
        if(u == 1){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    assert(false);
    return 0;
}
