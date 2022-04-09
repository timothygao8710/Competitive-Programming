//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

const int maxn = 32768;

string tobinary(int i){
    string s = bitset<64>(i).to_string();
    return s;
}

int main(){
    // cout << tobinary((1<<16) - 1) << endl;
    // cout << (1<<15) << endl;
    ios_base::sync_with_stdio(false); cin.tie(0);
    //actually 1<<15
    int N; cin >> N;
    for(int t = 0; t<N; t++){
        ll a; cin >> a;
        // if(a == 0){
        //     cout << 16 << '\n'; continue;
        // }
        int ret = 1e9;
        for(int i = 0; i<=24; i++){
            a += i;
            for(int j = 0; j<=24; j++){
                ll nxt = (a<<j) % maxn;
                if(nxt == 0){
                    ret = min(ret, j + i);
                }
            }
            a -= i;
        }
        cout << ret << " ";
    }
    return 0;
}
