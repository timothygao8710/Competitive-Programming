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
        int N; cin >> N;
        string s; cin >> s;
        int i = 0;
        for(; i<N; i++){
            if(s[i] != '0'){
                break;
            }
            cout << '0';
        }
        int ones = 0;
        int j = N-1;
        for(; j>=i; j--){
            if(s[j-1] == '1' && s[j] == '0'){
                break;
            }
            ones += (s[j] == '1');
        }
        j = max(j, i);
        if(s[j] == '0'){
            cout << '0';
        }
        for(int k = 0; k<ones; k++){
            cout << '1';
        }
        cout << '\n';
    }    

    return 0;
}
