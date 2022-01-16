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
        if((1+N)/2 < K){
            cout << -1 << endl; continue;
        }
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                if(i%2==0 && j%2==0 && i == j && K > 0){
                    cout << 'R'; K--;
                }else{
                    cout << '.';
                }
            }
            cout << '\n';
        }
    }

    return 0;
}
