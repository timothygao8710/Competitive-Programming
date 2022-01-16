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
    int T, N, a, b, c; cin >> T;
    while(T--){
        string str;
        cin >> N >> a >> b; cin >> str;
        int ret = N*a;
        vector<int> t; t.pb(0); t.pb(0);
        
        t[str[0] - '0']++;
        for(int i = 1; i<N; i++){
            if(str[i] != str[i-1]){
                t[str[i] - '0']++;
            }
        }
        if(b > 0){
            ret += N*b;
        }else{
            ret += (min(t[0], t[1])+1)*b;
        }
        cout << ret << '\n';
    }
    return 0;
}
