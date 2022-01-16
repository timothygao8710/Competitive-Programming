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

    int N, M; cin >> N >> M;
    vector<string> a(N), b(M);
    for(int i = 0; i<N; i++) cin >> a[i];
    for(int i = 0; i<M; i++) cin >> b[i];
    int Q; cin >> Q;
    while(Q--){
        int t; cin >> t; t--;
        cout << (a[t%N] + b[t%M]) << '\n';
    }

    return 0;
}
