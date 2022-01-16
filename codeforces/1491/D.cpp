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

    int N; cin >> N;
    for(int i = 0; i<N; i++){
        int from, to; cin >> from >> to;
        if(to < from) {
            cout << "NO" << '\n'; continue;
        }
        int run = 0, good = 1;
        for(int i = 0; i<=31; i++){
            run += (from>>i)&1;
            run -= (to>>i)&1;
            if(run < 0) good = 0;
        }
        cout << (good ? "YES" : "NO") << '\n';
    }

    return 0;
}
