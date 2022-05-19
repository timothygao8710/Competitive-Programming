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
        ll N, K; cin >> N >> K;
        ll sum = 0;
        vector<int> contrib;
        for(int i = 0; i<N; i++){
            int a; cin >> a;
            sum += a;
            contrib.pb(N - 1 - i - a);
        }
        sort(contrib.begin(), contrib.end());
        for(int i = 0; i<K; i++){
            sum += contrib[i];
        }
        sum -= (K-1) * K /2;
        // assert(sum);
        cout << sum << '\n';
    }    
    return 0;
}
