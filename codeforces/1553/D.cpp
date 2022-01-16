//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        string s, tar; cin >> s >> tar;
        set<int> locs[2][26];
        int dp[2] = {-1, -1};
        for(int i = 0; i<s.length(); i++){
            locs[i%2][s[i] - 'a'].insert(i);
        }
        int par[2] = {-2, -2};
        for(int i = 0; i<tar.length(); i++){
            for(int j = 0; j<2; j++){
                for(int k = 0; k<2; k++){
                    if(dp[k] == -2 || (dp[k] != -1 && j == k)) continue;
                    auto it = locs[j][tar[i] - 'a'].upper_bound(dp[k]);
                    if(it != locs[j][tar[i] - 'a'].end()){
                        par[j] = *it;
                    }
                }
            }
            dp[0] = par[0]; dp[1] = par[1];
            par[0] = par[1] = -2;
        }
        cout << (dp[(s.length()+1)%2] == -2 ? "NO" : "YES") << '\n';
    }
    return 0;
}
