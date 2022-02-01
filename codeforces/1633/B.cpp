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
        int diff = 0;
        for(char i : str){
            if(i=='1') diff++;
            if(i=='0') diff--;
        }
        if(abs(diff) == str.length() || str == "01" || str == "10"){
            cout << 0 << endl; continue;
        }
        if(diff == 0){
            cout << str.length()/2-1 << endl; continue;
        }
        cout << (str.length() - abs(diff))/2 << '\n';
    }    
    return 0;
}
