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
        if(str.size()%2){
            cout << "no\n";
        }else{
            bool good = 1;
            for(int i = 0; i<str.size()/2; i++){
                good = good && str[i] == str[str.size()/2 + i];
            }
            cout << (good ? "yes" : "no") << '\n';
        }
    }    
    return 0;
}
