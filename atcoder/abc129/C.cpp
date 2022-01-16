//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second
const int mod = 1e9+7;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, M; cin >> N >> M;
    vector<ll> dp(N+1);
    set<int> bruh;
    for(int i = 0; i<M; i++){
        int a; cin >> a; bruh.insert(a);
    }
    dp[0] = 1;
    for(int i = 1; i<=N; i++){
        if(bruh.count(i)) continue;
        if(i-1 >= 0) dp[i] += dp[i-1];
        if(i-2 >= 0) dp[i] += dp[i-2];
        dp[i] %= mod;
    }
    cout << dp[N];
    return 0;
}
