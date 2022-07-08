
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
        int N; cin >> N;
        vector<int> vis(N+1);
        vector<int> res;
        for(int i = 1; i<=N; i++){
            if(vis[i]) continue;
            int num = i;
            while(num <= N && !vis[num]){
                res.pb(num);
                vis[num] = 1;
                num *= 2;
            }
        }
        cout << 2 << '\n';
        for(int i : res){
            cout << i << " ";
        }
        cout << '\n';
    }    
    return 0;
}
