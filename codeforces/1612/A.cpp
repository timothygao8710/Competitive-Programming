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
        int x, y; cin >> x >> y;
        if((x+y)%2 != 0){
            cout << -1 << " " << -1 << endl; continue;
        }else{
            if(x > y){
                cout << y + (x - y)/2 <<  " " << 0 << endl; continue;
            }else{
                cout << 0 << " " << x + (y - x)/2 << endl; continue;
            }
        }
    }

    return 0;
}
