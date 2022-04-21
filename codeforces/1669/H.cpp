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
        vector<int> bits(31);
        for(int i = 0; i<N; i++){
            int a; cin >> a;
            for(int j = 0; j<=30; j++){
                if(((a>>j)&1) == 0){
                    bits[j]++;
                }
            }
        }
        int ret = 0;
        for(int i = 30; i>=0; i--){
            if(bits[i] <= K){
                K -= bits[i];
                ret += (1<<i);
            }
        }
        cout << ret << '\n';
    }
    return 0;
}
