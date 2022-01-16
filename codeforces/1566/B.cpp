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
        string str; cin >> str;
        set<int> con; 
        int a = 0, b = 0, c = 0;

        for(char i : str){
            con.insert(i);
            if(i == '0' && b){
                c = 1;
            }
            if(i == '0'){
                a = 1;
            }
            if(i == '1' && a){
                b = 1;
            }
        }

        if(!con.count('0')){
            cout << 0 << '\n';
        }else if(!con.count('1')){
            cout << 1 << '\n';
        }else{
            cout << (c ? 2 : 1) << '\n';
        }
    }    
    return 0;
}
