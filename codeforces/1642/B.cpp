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
        set<int> all; int N; cin >> N;
        for(int i = 0; i<N; i++) {
            int a; cin >> a; all.insert(a);
        }
        for(int i = 1; i<=N; i++){
            cout << max((int)(all.size()), i) << " ";
        }
        cout << '\n';
    }

    return 0;
}
