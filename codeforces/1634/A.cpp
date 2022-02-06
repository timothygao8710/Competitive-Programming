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
        int N, K; cin >> N >> K;
        string str; cin >> str;
        int pal = 1;
        for(int i = 0; i<N/2; i++){
            pal = pal && str[i] == str[N-1-i];
            // cout << str[i] << " "<< str[N-1-i] << endl;
        }
        if(K == 0){
            cout << 1 << endl; continue;
        }
        cout << (pal ? 1 : 2) << '\n';
    }    
    return 0;
}
