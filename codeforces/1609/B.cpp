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
    int N, Q; cin >> N >> Q;
    string str; cin >> str;
    vector<int> bad(N); int ret = 0;
    for(int i = 0; i<N-2; i++){
        if(str[i] == 'a' && str[i+1] == 'b' && str[i+2] == 'c'){
            bad[i]=1; ret++;
        }
    }
    while(Q--){
        char c; int loc; cin >> loc >> c; --loc;
        if(c == str[loc]){
            cout << ret << '\n'; continue;
        }
        str[loc] = c;
        // cout << str << endl;
        for(int i = loc-2; i<=loc; i++){
            if(i < 0) continue;
            if(i+2 < N && str[i] == 'a' && str[i+1] == 'b' && str[i+2] == 'c') {
                assert(!bad[i]);
                bad[i] = 1, ret++;
            }else if(bad[i]){
                bad[i] = 0, ret--;
            }
        }
        cout << ret << '\n';
    }
    return 0;
}
