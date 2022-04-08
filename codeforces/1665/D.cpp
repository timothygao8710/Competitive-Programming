//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

int ask(int a, int b){
    cout << "? " << a << " " << b << endl;
    int c; cin >> c; return c;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        //bits 0...29
        int ret = 0, add = 1;
        for(int i = 0; i<30; i++){
            int cur = ask(add, add + (1<<(1+i))) == (1<<(1+i)); 
            //(1<<(1+i)) or not
            // if(add == 1){
            //     ret += (cur<<i);
            //     if(cur == 1) {
            //         add = (1<<(1+i));
            //     }
            // }else{
                // cur ^= 1;
                ret += (cur<<i);
                if(cur == 0) add += (1<<i);
            // }
        }
        cout << "! " << ret << endl;
    }    
    return 0;
}
