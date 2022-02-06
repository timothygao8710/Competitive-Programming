//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

void print(vector<int>& v, int K){
    int N = (int)(v.size());
    for(int i = 0; i<N;){
        int j = 0;
        for(; j<K; j++, i++){
            cout << v[i] << " ";
        }
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N, K; cin >> N >> K;
        vector<int> odds, evens;
        for(int i = 1; i<=N*K; i++){
            if(i%2){
                odds.pb(i);
            }else{
                evens.pb(i);
            }
        }

        if(odds.size()%K != 0  || evens.size()%K != 0){
            cout << "NO" << '\n'; continue;
        }
        cout << "YES" << '\n';
        // for(int i : odds) cout << i << endl;
        print(odds, K);
        print(evens, K);
    }    
    return 0;
}
