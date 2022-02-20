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
        int N; cin >> N; int ret = 0;
        for(int i = 0; i<N; i++){
            int a;cin>> a; ret |= a;
        }       
        cout << ret << '\n';
    }
    return 0;
}
