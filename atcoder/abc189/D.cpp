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
    int N; cin >> N;
    vector<ll> dp(2); dp[0] = dp[1] = 1;
    while(N--){
        string s; cin >> s;
        vector<ll> ndp(2);
        if(s == "AND"){
            ndp[1] = dp[1];
            ndp[0] = dp[1] + 2*dp[0];
        }else{
            ndp[0] = dp[0];
            ndp[1] = dp[0] + 2*dp[1];
        }
        swap(ndp, dp);
    }
    cout << dp[1];
    return 0;
}
