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
        string str; cin >> str;
        for(int i = 0; i<N; i++){
            if(str[i] == 'L' || str[i] == 'R'){
                cout << "LR"; i++;
            }else if(str[i] == 'D'){
                cout << 'U';
            }else{
                cout << 'D';
            }
        }
        cout << '\n';
    }
    return 0;
}
