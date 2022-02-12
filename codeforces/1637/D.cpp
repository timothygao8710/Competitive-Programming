//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

const int maxs = 1e4 + 400;
const int maxn = 105;

int dp[maxn][maxs];
vector<int> a(maxn), b(maxn), c(maxn);
int N;

int memo(int idx = 0, int sum = 0, int other = 0){
    assert(sum < maxs);
    if(idx == N) return 0;
    if(dp[idx][sum] != (int)(2e9)) return dp[idx][sum];
    dp[idx][sum] = min(
        memo(idx+1, a[idx] + sum, b[idx] + other) + 2*a[idx]*sum + 2*b[idx]*other,
        memo(idx+1, b[idx] + sum, a[idx] + other) + 2*b[idx]*sum + 2*a[idx]*other
    );
    return dp[idx][sum];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        cin >> N;
        ll ret = 0;
        for(int i = 0; i<N; i++) cin >> a[i], ret += (N-1)*a[i]*a[i];
        for(int i = 0; i<N; i++) cin >> b[i], ret += (N-1)*b[i]*b[i];
        for(int i = 0; i<N; i++){
            for(int j = 0; j<101*N; j++){
                dp[i][j] = 2e9;
            }
        }
        ret += memo();
        cout << ret << '\n';
    }
    return 0;
}
