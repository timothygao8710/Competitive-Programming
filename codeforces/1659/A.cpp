
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
        int N, R, B; cin >> N >> R >> B;
        //b < r
        vector<string> spots(B+1);
        for(int i = 0; i<R; i++){
            spots[i%(B+1)] += 'R';
        }
        cout << spots[0];
        for(int i = 0; i<B; i++){
            cout << 'B' << spots[i+1];
        }
        cout << '\n';
    }    
    return 0;
}
