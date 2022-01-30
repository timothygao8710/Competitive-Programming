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
        int N; cin >> N;
        string str; cin >> str;
        int a = 0, b = 0;
        for(char i : str){
            if(i == '1') a++;
            if(i == '0') b++;
        }
        cout << (a <= 1 && b <= 1 ? "YES" : "NO") << '\n';
    }    
    return 0;
}
