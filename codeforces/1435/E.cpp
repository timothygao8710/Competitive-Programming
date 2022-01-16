//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

ll T, dam, heal, len, dist;
ll calc(ll times){
    return dam*times - heal*dist*((times+1)*(times)/2);
}

/*
y = (x-(2a-bc)/(2cb))^2...
*/

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    //you get a quadratic equation
    cin >> T;
    while(T--){
        cin >> dam >> heal >> len >> dist;
        if(dam > heal*len){
            cout << -1 << "\n"; continue;
        }
        if(dist >= len){
            cout << dam << "\n"; continue;
        }
        // for(int i = 1; i<100; i++){
        //     // cout << calc(i) << " ";
        // }
        // cout << endl;
        int l = 1; int r = len+69;
        while(l < r){
            int mid = (l+r+1)/2;
            ll rr = calc(mid), ll = calc(mid-1);
            if(ll >= rr){
                r = mid-1;
            }else{
                l = mid;
            }
        }
        double temp = 1.0;
        double vertex = (
          (temp*2*dam - temp*dist*heal)/(temp*2*heal*dist)  
        );

        // cout << vertex << " " << l << endl;
        cout << (max((ll)0,calc(round(vertex)))+dam) << endl;
        // cout << (max((ll)0,calc(l))+dam) << endl;
    }    
    return 0;
}