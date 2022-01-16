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
        vector<char> ret;
        int last = 0;
        int N; cin >> N; string str; cin >> str;
        for(int i = 0; i<N; i++){
            char a = str[i];
            if(!ret.empty() && ret[ret.size()-1] < a) break;
            if(!ret.empty() && a != ret[ret.size()-1]) last++;
            ret.pb(a);
        }
        if((int)ret.size() > 1 && str[0] == str[1]){
            cout << str[0] << str[0] << '\n'; continue;
        }
        
        for(char i : ret){
            cout << i;
        }
        reverse(ret.begin(), ret.end());
        for(char i : ret){
            cout << i;
        }
        cout << '\n';
    }    
    return 0;
}
