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
        int N; cin >> N; string str; cin >> str;
        int idx = -1;
        for(int i = 0; i<N; i++){
            idx += str[i] == '0';
        }
        vector<int> all;
        for(int i = 0; i<N; i++){
            if(str[i] == '1' && i <= idx){
                all.pb(i+1);
            }else if(str[i] == '0' && i > idx){
                all.pb(i+1);
            }
        }
        if(all.size()) cout << 1 << "\n";
        cout << all.size() << " ";
        for(int i : all) cout << i <<  " ";
        cout << '\n';
    }    
    return 0;
}
