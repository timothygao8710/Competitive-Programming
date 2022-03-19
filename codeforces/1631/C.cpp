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
        if(N == 4 && K == 3) {
            cout << -1 << '\n'; continue;
        }

        if(K == N-1){
            cout << N-1 << " " << N-2 << '\n';
            cout << N-3 << " " << 1 << '\n';
            cout << 0 << " " << 2 << '\n';
            for(int i = 3; i<N/2; i++){
                cout << i << " " << (N-1-i) << '\n';
            }
            continue;
        }

        cout << K << " " << N-1 << '\n';
        set<int> has; has.insert(N-1); has.insert(K);
        for(int i = 1; i<N; i++){
            if(has.count(i)) continue;
            if(has.count(N-1-i)){
                assert(i == N-1-K);
                cout << 0 << " " << i << '\n';
            }else{
                cout << i << " " << N-1-i << '\n';
            }
            has.insert(i);
            has.insert(N-1-i);
        }
    }    
    return 0;
}
