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
        int mn = INT_MAX;
        for(int i = 0;i<(int)str.length(); i++){
            mn = min(mn, str[i] - '0');
        }
        if(str.length() == 2){
            cout << str[str.length()-1] << '\n';
        }else{
            cout << mn << '\n';
        }
    }    
    return 0;
}
