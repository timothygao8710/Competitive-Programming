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
        string str; cin >> str;
        set<char> has, tw;
        vector<char> twice; 
        for(char i : str){
            if(has.count(i)) twice.pb(i), tw.insert(i);
            has.insert(i);
        }
        for(auto i : twice) cout << i;
        for(char i : has){
            if(!tw.count(i)) cout << i;
        }
        for(auto i : twice) cout << i;
        cout << '\n';
    }
    return 0;
}
